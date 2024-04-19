#pragma once
#include "offsets.h"
#include <stdio.h>
#include "kiero/minhook/include/MinHook.h"
#include "globals.h"


namespace PlayerInventory
{

    // AddCoins Hook

    void(__fastcall* AddCoins_orig)(DWORD*, double, DWORD*);

    void __fastcall AddCoins_Hook(DWORD* __this, double coins, DWORD* method)
    {
        if (globals::InfCoins)
            coins = 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.0;

        // Call the original function
        AddCoins_orig(__this, coins, method);
    }

    void AddCoinsFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + AddCoins), AddCoins_Hook, reinterpret_cast<LPVOID*>(&AddCoins_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + AddCoins));

        printf("AddCoins Hooked\n");
    }
}

namespace PlayerWeapons
{
    // ShootArrow Hook

    void(__fastcall* ShootArrow_orig)(DWORD*, DWORD*);

    void __fastcall ShootArrow_Hook(DWORD* __this, DWORD* method)
    {
        if (globals::InfShoot)
            ShootArrow_orig(__this, method);
    }

    void ShootArrowFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + ShootArrow), ShootArrow_Hook, reinterpret_cast<LPVOID*>(&ShootArrow_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + ShootArrow));

        printf("ShootArrow Hooked\n");
    }

    // IsShootingArrow Hook

    bool(__fastcall* IsShootingArrow_orig)(DWORD*, DWORD*);

    bool __fastcall IsShootingArrow_Hook(DWORD* __this, DWORD* method)
    {
        return false;
    }

    void IsShootingArrowFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + IsShootingArrow), ShootArrow_Hook, reinterpret_cast<LPVOID*>(&IsShootingArrow_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + IsShootingArrow));

        printf("IsShootingArrow Hooked\n");
    }
}

namespace PlayerMovement {

    // IsGrounded Hook

    bool(__fastcall* IsGrounded_orig)(DWORD*, DWORD*);

    bool __fastcall IsGrounded_Hook(DWORD* __this, DWORD* method)
    {
        if (globals::InfJump)
        {
            return true;
        }
        // If globals::IsGrounded is false, don't return anything
        return IsGrounded_orig(__this, method);
    }

    void IsGroundedFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + IsGrounded), IsGrounded_Hook, reinterpret_cast<LPVOID*>(&IsGrounded_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + IsGrounded));

        printf("IsGrounded Hooked\n");
    }

    // boostCD hook

    void(__fastcall* FastBoost_orig)(DWORD*, float, DWORD*);

    void __fastcall FastBoost_Hook(DWORD* this__, float decrease, DWORD* method)
    {
        if (globals::FastBoost)
            decrease = 99999.0f;

        FastBoost_orig(this__, decrease, method);
    }

    void FastBoostFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + boostCD), FastBoost_Hook, reinterpret_cast<LPVOID*>(&FastBoost_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + boostCD));

        printf("boostCD Hooked\n");
    }

    // RagemodeCD hook

    void(__fastcall* Ragemode_orig)(DWORD*, float, DWORD*);

    void __fastcall Ragemode_Hook(DWORD* this__, float decrease, DWORD* method)
    {
        if (globals::FastRage)
            decrease = 99999.0f;

        Ragemode_orig(this__, decrease, method);
    }

    void RagemodeFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + RagemodeCD), Ragemode_Hook, reinterpret_cast<LPVOID*>(&Ragemode_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + RagemodeCD));

        printf("RagemodeCD Hooked\n");
    }
}

namespace World
{
    // SpawnPortal hook ( doesnt work as of now )

    void(__fastcall* PortalCD_orig)(DWORD*, DWORD*);

    void __fastcall PortalCD_Hook(DWORD* this__, DWORD* method)
    {
        if (globals::FastPortal)
            PortalCD_orig(this__, method);
    }

    void FastPortalFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + PortalCD), PortalCD_Hook, reinterpret_cast<LPVOID*>(&PortalCD_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + PortalCD));

        printf("SpawnPortal Hooked\n");
    }
}