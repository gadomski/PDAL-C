:: Helper script for vcpkg-based x64-windows vscode build tasks
@echo off

:: This script assumes that cmake is in PATH
:: TODO Auto-detect latest platform
set SCRIPT_DIR=%~dp0

if not defined TOOLCHAIN set TOOLCHAIN=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
if not defined BUILD_TYPE set BUILD_TYPE=Release
if not defined ARCH set ARCH=x64
if not defined TARGET_OS set TARGET_OS=windows

set TRIPLET=%ARCH%-%TARGET_OS%

set BUILD_DIR=%SCRIPT_DIR%\build\%TRIPLET%

if exist "%BUILD_DIR%\pdal-c.sln" (
	pushd "%BUILD_DIR%"
) else (
	mkdir "%BUILD_DIR%"
	pushd "%BUILD_DIR%"

	cmake ../.. ^
		-DCMAKE_BUILD_TYPE=%BUILD_TYPE% ^
		-DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN% ^
		-DVCPKG_TARGET_TRIPLET=%TRIPLET% ^
		-DCMAKE_GENERATOR_PLATFORM=%ARCH%
)

:: Build and install solution
cmake --build . --target INSTALL --config %BUILD_TYPE%

popd

