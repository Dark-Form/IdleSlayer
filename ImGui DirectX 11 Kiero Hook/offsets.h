#pragma once

uintptr_t gameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");

// PlayerInventory
uintptr_t AddCoins = 0x35E410; // PlayerInventory$$AddCoins
uintptr_t CPSBonusBought = 0x363E00; // JewelsOfSoulManager$$CPSBonusBought

// PlayerWeapons
uintptr_t ShootArrow = 0x22BDD0; // PlayerMovement$$ShootArrow
uintptr_t IsShootingArrow = 0x22B560; // PlayerMovement$$IsShootingArrow

// PlayerMovement
uintptr_t BoostIsActive = 0x2B8EE0; // SpiritBoost$$PickedUp
uintptr_t IsGrounded = 0x22B350; // PlayerMovement$$IsGrounded

// Abilities
uintptr_t DecreaseCD = 0x2403A0; // Ability$$DecreaseCD