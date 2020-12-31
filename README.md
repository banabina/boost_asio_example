## boost_asio_example
- 홍정모의 따라하며 배우는 C++ 강의
20.5 TCP IP 네트워킹 맛보기 \- Boost.Asio Socker IOStream의 예제코드

## Boost 설치
- vcpkg을 활용하여 설치

vcpkg 설치
```
> git clone https://github.com/microsoft/vcpkg
> .\vcpkg\bootstrap-vcpkg.bat
```

boost 설치
```
> .\vcpkg\vcpkg install boost
```

vcpkg를 Visual Studio에서 사용
```
> .\vcpkg\vcpkg integrate install
```

## 사용
1. Boost_Asio_Client 솔루션의 Command Argument을 127.0.0.1로 설정한다. 
2. Boost_Asio_Server 프로젝트를 먼저 실행하고 Boost_Asio_Client 프로젝트를 실행한다.
