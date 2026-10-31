@echo off
setlocal EnableDelayedExpansion
"%SystemRoot%\System32\chcp.com" 936 >nul
set "PATH=%SystemRoot%\System32;%SystemRoot%;%PATH%"
if exist "%ProgramFiles%\Git\cmd" set "PATH=%ProgramFiles%\Git\cmd;%PATH%"
cd /d "%~dp0"
title 一键同步到 GitHub - C-Practice

echo ================================================
echo            一键同步代码到 GitHub
echo            仓库: leejh2008/C-Practice
echo ================================================
echo.

where git >nul 2>nul
if errorlevel 1 (
    echo [错误] 没有找到 git，请先安装 Git for Windows。
    echo        找不到的话，安装时记得勾选 "Add to PATH"。
    goto :theend
)

if not exist ".git" (
    echo [错误] 当前文件夹不是 Git 仓库，请检查脚本所在路径是否正确。
    echo        当前路径: %~dp0
    goto :theend
)

echo [1/4] 检查本地改动...
git add -A
git diff --cached --quiet
if not errorlevel 1 (
    echo       没有新的改动，跳过提交。^(代码可能没保存，或本来就还没改^)
    goto :pushpart
)
echo       已暂存所有改动。

echo.
echo [2/4] 生成提交说明...
set STAMP=%date% %time%
set MSGFILE=
powershell -NoProfile -Command "$m='自动同步 '+$env:STAMP; [IO.File]::WriteAllText($env:TEMP+'\git_msg.txt',$m,(New-Object Text.UTF8Encoding $false))"
if exist "%TEMP%\git_msg.txt" set MSGFILE=%TEMP%\git_msg.txt

echo.
echo [3/4] 提交...
if defined MSGFILE (
    git commit -F "!MSGFILE!" >nul 2>&1
) else (
    git commit -m "auto sync" >nul 2>&1
)
if errorlevel 1 (
    echo       [警告] 提交失败，当前状态如下：
    git status --short
) else (
    echo       提交成功。
)
if defined MSGFILE del "!MSGFILE!" >nul 2>nul

:pushpart
echo.
echo [4/4] 上传到 GitHub...
set OK=0
set PUSHLOG=%TEMP%\github_push_log.txt

for /l %%n in (1,1,3) do (
    if "!OK!"=="0" (
        git push > "!PUSHLOG!" 2>&1
        if errorlevel 1 (
            echo       [第 %%n 次上传失败，3 秒后重试...]
            timeout /t 3 /nobreak >nul
        ) else (
            set OK=1
        )
    )
)

echo.
if "!OK!"=="1" (
    echo ================================================
    echo   同步完成！
    echo   网页查看: https://github.com/leejh2008/C-Practice
    echo ================================================
) else (
    echo ================================================
    echo   上传失败，最后一次的报错如下：
    echo ------------------------------------------------
    if exist "!PUSHLOG!" type "!PUSHLOG!"
    echo ------------------------------------------------
    echo   常见原因：
    echo   1^) 代理软件没开，git 需要 127.0.0.1:7897
    echo   2^) 令牌已过期，需要重新生成并输入
    echo   3^) 网络不通或 GitHub 访问受限
    echo ================================================
)
if exist "!PUSHLOG!" del "!PUSHLOG!" >nul 2>nul

:theend
echo.
echo 按任意键关闭窗口...
pause >nul
