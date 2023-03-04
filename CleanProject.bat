RD /s /Q .\Build
RD /s /Q .\Binaries
RD /s /Q .\Intermediate
RD /s /Q .\Saved
RD /s /Q .\.vs
del *.sln

@if "%1"=="--deep" (
    @for /f %%p in ('dir /B /A:D Plugins') do @(
        del /s /q Plugins\%%p\Binaries
        del /s /q Plugins\%%p\Intermediate
    )
)


PAUSE
