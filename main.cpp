#include "robot.h"
#include "robot_types.h"
#include "robot_error.h"
#include <iostream>

int TestRobotCtrl(FRRobot *robot);
int TestJOG(FRRobot *robot);

int main()
{
    FRRobot robot;
    robot.LoggerInit();
    robot.SetLoggerLevel(1);

    int rtn = robot.RPC("192.168.222.129");
    if (rtn != 0)
    {
        std::cerr << "Error" << rtn << std::endl;
        return -1;
    }

    std::cout << "Great Conexion" << std::endl;

    int rtn2 = TestRobotCtrl(&robot);
    if (rtn2 != 0)
    {
        std::cerr << "Error in RobotCtrl: " << rtn2 << std::endl;
        return -1;
    }

    int rtn3 = TestJOG(&robot);
    if (rtn3 != 0)
    {
        std::cerr << "Error in JOG: " << rtn3 << std::endl;
        return -1;
    }

    robot.CloseRPC();
    std::cout << "Program finished cleanly." << std::endl;
    return 0;
}

int TestRobotCtrl(FRRobot *robot)
{

    robot->SetReConnectParam(true, 30000, 500);
    char ip[64] = "";
    char version[64] = "";
    uint8_t state;
    robot->GetSDKVersion(version);
    printf("SDK version:%s\n", version);

    robot->GetControllerIP(ip);
    printf("controller ip:%s\n", ip);

    robot->Mode(1);
    robot->Sleep(1000);

    robot->DragTeachSwitch(1);
    robot->Sleep(1000);

    robot->IsInDragTeach(&state);
    printf("drag state :%u\n", state);
    robot->Sleep(3000);

    robot->DragTeachSwitch(0);
    robot->Sleep(1000);

    robot->IsInDragTeach(&state);
    printf("drag state :%u\n", state);
    robot->Sleep(3000);

    robot->RobotEnable(0);
    robot->Sleep(3000);

    robot->RobotEnable(1);
    robot->Mode(0);
    robot->Sleep(1000);

    robot->Mode(1);
    robot->Sleep(3000);
    //robot.ShutDownRobotOS();
    //robot.CloseRPC();
    return 0;
}

int TestJOG(FRRobot *robot)
{
    robot->SetReConnectParam(true, 30000, 500);

    for (int i = 0; i < 6; i++)
    {
        robot->StartJOG(0, i + 1, 0, 20.0, 20.0, 30.0);
        robot->Sleep(1000);
        robot->ImmStopJOG();
        robot->Sleep(1000);
    }
    for (int i = 0; i < 6; i++)
    {
        robot->StartJOG(2, i + 1, 0, 20.0, 20.0, 30.0);
        robot->Sleep(1000);
        robot->ImmStopJOG();
        robot->Sleep(1000);
    }
    for (int i = 0; i < 6; i++)
    {
        robot->StartJOG(4, i + 1, 0, 20.0, 20.0, 30.0);
        robot->Sleep(1000);
        robot->StopJOG(5);
        robot->Sleep(1000);
    }
    for (int i = 0; i < 6; i++)
    {
        robot->StartJOG(8, i + 1, 0, 20.0, 20.0, 30.0);
        robot->Sleep(1000);
        robot->StopJOG(9);
        robot->Sleep(1000);
    }
    return 0;
}