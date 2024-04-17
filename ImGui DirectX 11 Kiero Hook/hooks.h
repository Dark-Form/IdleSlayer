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

    // Attack Hook

    void(__fastcall* Attack_orig)(DWORD*, DWORD*);

    void __fastcall Attack_Hook(DWORD* __this, DWORD* method)
    {
        if (globals::InfAttack)
            Attack_orig(__this, method);
    }

    void AttackFunc()
    {
        // Create hook
        MH_CreateHook((LPVOID)(gameAssembly + Attack), Attack_Hook, reinterpret_cast<LPVOID*>(&Attack_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + Attack));

        printf("ShootArrow Hooked\n");
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

    // DecreaseCD hook

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
        MH_CreateHook((LPVOID)(gameAssembly + DecreaseCD), FastBoost_Hook, reinterpret_cast<LPVOID*>(&FastBoost_orig));

        // Enable hook
        MH_EnableHook((LPVOID)(gameAssembly + DecreaseCD));

        printf("DecreaseCD Hooked\n");
    }
}