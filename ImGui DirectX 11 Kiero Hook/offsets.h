#pragma once

uintptr_t gameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

// PlayerInventory
uintptr_t AddCoins = 0x35E410; // PlayerInventory$$AddCoins

// PlayerWeapons
uintptr_t ShootArrow = 0x22BDD0; // PlayerMovement$$ShootArrow
uintptr_t IsShootingArrow = 0x22B560; // PlayerMovement$$IsShootingArrow
uintptr_t Attack = 0x22A2B0; // PlayerMovement$$Attack
uintptr_t IsAttacking = 0x22B250; // PlayerMovement$$IsAttacking

// PlayerMovement
uintptr_t BoostIsActive = 0x2B8EE0; // SpiritBoost$$PickedUp
uintptr_t IsGrounded = 0x22B350; // PlayerMovement$$IsGrounded
uintptr_t TrailEffect = 0x22D420; // PlayerMovement$$TrailEffect

// Abilities
uintptr_t DecreaseCD = 0x2403A0; // Ability$$DecreaseCD