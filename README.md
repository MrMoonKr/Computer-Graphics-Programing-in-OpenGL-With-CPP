# Computer-Graphics-Programing-in-OpenGL-With-CPP

WIP ( Work in Progrss )  

학생들을 위한 OpenGL 직무 교육( OJT, On the job Training )을 위해서 생성 하였습니다.  


## 책 관련 링크  

- [Computer Graphics Programming in OpenGL with C++ 3rd [ 원서 ]](https://athena.ecs.csus.edu/~gordonvs/textC3E.html)  

- [저자 홈페이지](https://athena.ecs.csus.edu/~gordonvs/)  


## 개발 및 테스트 환경

- 시스템 ( Computer System )  

  - AMD Ryzen 9 5900X 12-Core Processor
  - NVIDIA Geforce RTX 3080 10GB
  - Windows 11 64bit Korean

- 컴파일러 및 링커 ( Compiler , Linker )  

  - [Visual Studio Community 2022](https://visualstudio.microsoft.com/ko/free-developer-offers/)  
    - C++를 사용한 데스크톱 개발  
    - C++를 사용한 게임 개발  

  - [~~MingGW-w64 via MSYS2~~](https://code.visualstudio.com/docs/cpp/config-mingw)
    - 당분간 테스트 없음  
    - [설치파일](https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe)
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

- 에디터 ( Editor, Intergrated Development Environment )  

  - [VS Code](https://visualstudio.microsoft.com/ko/free-developer-offers/)  
    - C/C++ Extension for VS Code
      - c_cpp_properties.json ( compiler path and IntelliSense settings )  
      - tasks.json ( build instructions )  
      - launch.json ( debugger settings )  
      - Chapter01 동작 테스트 후 CMake 도입함.  

- 빌드 매니저 ( Build Manager )
  - [CMake](https://cmake.org/)  
    - [설치](https://cmake.org/download/)  
    - ...
    ```
    $ cmake --version
    ```
  - CMakeLists.txt
  - CMakePresets.json
  - CMakeUserPresets.json

- 패키지 매니저 ( Package Manager )
  - [vcpkg](https://vcpkg.io/en/)  
    - [설치](https://github.com/microsoft/vcpkg)  
    - ...
    ```
    $ vcpkg --version
    $ vcpkg new --application
    ```
  - vcpkg.json
  - vcpkg-configuration.json


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

- STB
  - [vcpkg](https://vcpkg.io/en/package/stb)  
  ```
  $ vcpkg add port stb
  ```
  - [stb](https://github.com/nothings/stb)
  - Image Loader

- IMGUI
  - [vcpkg](https://vcpkg.io/en/package/imgui)  
  ```
  $ vcpkg add port imgui[glfw-binding,opengl3-binding,freetype]
  ```
  - [imgui](https://github.com/ocornut/imgui)
  - Immediate Mode Graphical User Interface

- SOIL2
  - [vcpkg](https://vcpkg.io/en/package/soil2)  
  ```
  $ vcpkg add port soil2
  ```
  - [SOIL2](https://github.com/SpartanJ/SOIL2)
  - Simple OpenGL Image Library 2

- ...
  - [vcpkg]()  
  ```
  $ vcpkg add port ...
  ```
  - [...]()
  - ...

## ...

---
---
---

