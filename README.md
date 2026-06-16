# Fairino Cobot C++ SDK Integration Guide (Linux/Ubuntu)

This repository provides the pre-compiled C++ SDK components and deployment examples required to interface with Fairino collaborative robots within a Linux Ubuntu environment.

## Repository Structure


 ```text
📦 fairino-cpp-sdk-distribution
 ┣ 📂 include                  # Native C++ SDK core header mappings
 ┃ ┣ 📜 robot.h
 ┃ ┣ 📜 robot_error.h
 ┃ ┗ 📜 robot_types.h
 ┣ 📂 lib/lib                  # Dynamic shared objects binaries (.so)
 ┃ ┗ 📜 libfairino.so.2.3.6
 ┃ ┗ 📜 libfairino.so.2
 ┃ ┗ 📜 libfairino.so
 ┣ 📜 main.cpp                 # Verified edge tracking implementation script
 ┗ 📜 README.md                # Infrastructure deployment documentation
 ```

Technical Prerequisites
Before initializing compilation tasks, configure your Linux environment with the essential GNU C++ toolchains and build subsystems:

 ```text
sudo apt update
sudo apt install build-essential cmake -y
 ```

# Compilation and Linkage Protocol
C++ source objects must explicitly map header inclusions and link the binary shared object target (libfairino.so). Run the standard compilation command from your project root:

 ```text
g++ examples/main.cpp -I./include -L./lib -lfairino -o robot_app -Wl,-rpath,./lib
 ```

Argument Specifications:
-I./include: Appends the SDK development headers directory to the primary compiler search path map.
-L./lib: Declares the search directory containing binary shared object assets used during linking routines.
-lfairino: Directs the linker to resolve functional symbols against libfairino.so.
-o robot_app: Determines the name of the final generated native executable binary.


Launching the Application:
Once the compiler creates the native binary asset, trigger execution directly via terminal:

 ```text
LD_LIBRARY_PATH=./lib ./robot_app
 ```

<p align="center">
  <a href="https://youtu.be/JGQjcBxVxYA" target="_blank">
    <img src="https://youtu.be/JGQjcBxVxYA/maxresdefault.jpg" alt="Fairino C++ SDK Sequence Demonstration" width="100%" style="border-radius: 8px;">
  </a>
</p>

<p align="center">
  ▶️ <i>Click above to watch the full execution breakdown on YouTube</i>
</p>
