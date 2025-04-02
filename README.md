# Computer-Graphics-Programing-in-OpenGL-With-CPP

WIP ( Work in Progrss )  

학생들을 위한 OpenGL 직무 교육( OJT, On the job Training )을 위해서 생성 하였습니다.  
최신 버전 네이티브 개발 환경으로 프로젝트를 구성 하였습니다.  


## 책 관련 링크  

- [Computer Graphics Programming in OpenGL with C++ 3rd [ 원서 ]](https://athena.ecs.csus.edu/~gordonvs/textC3E.html)  

- [저자 홈페이지](https://athena.ecs.csus.edu/~gordonvs/)  


## 개발 및 테스트 환경  

MinGW 환경에서 Visual Studio C++ 2022 환경으로 변경함.  
추후 MinGW 거쳐서 WSL 우분투 환경까지 테스트 필요함.  

- [개발 환경 구축](https://code.visualstudio.com/docs/cpp/config-mingw)  

- Windows 11 64bit  

- ~~MinGW-w64 via MSYS2~~
  ```
  $ pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
  ```
  ```
  // 시스템 환경 변수 'PATH' 에 추가 등록  
  C:\msys64\ucrt64\bin
  ```
  ```
  $ gcc --version
  $ g++ --version
  $ gdb --version
  ```

- Visual Studio Community 2022  
  - C++를 사용한 데스크톱 개발  
  - C++를 사용한 게임 개발  

- VS Code  
  - C/C++ Extension for VS Code
    - c_cpp_properties.json ( compiler path and IntelliSense settings )  
    - tasks.json ( build instructions )  
    - launch.json ( debugger settings )  
    - Chapter01 동작 테스트 후 CMake 도입함.  

- CMake  
  - 설치  
  - ...
  ```
  $ cmake --version
  ```

- vcpkg  
  - 설치  
  - ...
  ```
  $ vcpkg --version
  $ vcpkg new --application
  ```

- ...


## 사용된 패키지 목록

- GLAD
  - [vcpkg](https://vcpkg.io/en/package/glad)
    ```
    $ vcpkg add port glad[gl-api-43]
    ```
  - [GLAD](https://glad.dav1d.de/)  
  - C/C++ OpenGL Core 4.3 API

- GLFW
  - [vcpkg](https://vcpkg.io/en/package/glfw3)
    ```
    $ vcpkg add port glfw3
    ```
  - [GLFW](https://www.glfw.org/download.html)
  - [Windows Pre-Compiled Binaries](https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.bin.WIN64.zip)
  - glfw 3.4 win64

- GLM
  - [vcpkg](https://vcpkg.io/en/package/glm)  
    ```
    $ vcpkg add port glm
    ```
  - [glm](https://github.com/g-truc/glm)
  - OpenGL Mathematics  

- ...  
  ```
  $ ...
  ```
- ... 
  ```
  $ ...
  ```

## ...

---
---
---
