@echo off
setlocal EnableDelayedExpansion
chcp 936 >nul
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
    goto :theend
)

if not exist ".git" (
    echo [错误] 当前文件夹不是 Git 仓库，请检查脚本所在路径是否正确。
    echo        当前路径: %~dp0
    goto :theend
)

echo [1/3] 检查本地改动...
git add -A
set CHANGED=
for /f %%i in ('git status --porcelain') do set CHANGED=1

if not defined CHANGED (
    echo       没有新的改动，跳过提交。^(代码可能没保存，或本来就还没改^)
    goto :pushpart
)
echo       已暂存所有改动。

echo.
echo [2/3] 提交并写时间说明...
set STAMP=%date% %time%
powershell -NoProfile -Command "Set-Content -LiteralPath $env:TEMP\git_msg.txt -Value ('自动同步 ' + $env:STAMP) -Encoding utf8"
git commit -F "%TEMP%\git_msg.txt" >nul
set CERR=!errorlevel!
del "%TEMP%\git_msg.txt" >nul 2>nul
if not "!CERR!"=="0" (
    echo       [警告] 提交失败，请看上面的英文提示。
) else (
    echo       提交成功。
)

:pushpart
echo.
echo [3/3] 上传到 GitHub...
set OK=0
for /l %%n in (1,1,3) do (
    if "!OK!"=="0" (
        git push
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
    echo   上传失败，常见原因：
    echo   1^) 代理软件没开，git 需要 127.0.0.1:7897
    echo   2^) 令牌已过期，需要重新生成并输入
    echo   3^) 网络不通或 GitHub 访问受限
    echo ================================================
)

:theend
echo.
echo 按任意键关闭窗口...
pause >nul
