#pragma once

#include <Windows.h>
#include <Uxtheme.h>
#include <VersionHelpers.h>

bool IsDarkModeAllowed();
bool ShouldAppsUseDarkMode();

static constexpr LPCSTR iniFilePath = "Settings.ini"; // Removed the "L" prefix

static void setINIValuesAtStartup() {
    // Implementation of setINIValuesAtStartup
    // You can use Windows API functions here
    if (IsDarkModeAllowed() && ShouldAppsUseDarkMode()) {
                WritePrivateProfileStringA("DisplaySettings", "DisplayDarkMode", "true", iniFilePath); // Removed the "L" prefix
    }
}