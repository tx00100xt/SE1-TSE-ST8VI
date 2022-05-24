/* Copyright (c) 2002-2012 Croteam Ltd. 
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#include "StdAfx.h"
#include "Game.h"

extern FLOAT gam_afEnemyMovementSpeed[5];
extern FLOAT gam_afEnemyAttackSpeed[5];
extern FLOAT gam_afDamageStrength[5];
extern FLOAT gam_afAmmoQuantity[5];
extern FLOAT gam_fManaTransferFactor;
extern FLOAT gam_fExtraEnemyStrength          ;
extern FLOAT gam_fExtraEnemyStrengthPerPlayer ;
extern INDEX gam_iCredits;
extern FLOAT gam_tmSpawnInvulnerability;
extern INDEX gam_iScoreLimit;
extern INDEX gam_iFragLimit;
extern INDEX gam_iTimeLimit;
extern INDEX gam_ctMaxPlayers;
extern INDEX gam_bWaitAllPlayers;
extern INDEX gam_bAmmoStays       ;
extern INDEX gam_bHealthArmorStays;
extern INDEX gam_bAllowHealth     ;
extern INDEX gam_bAllowArmor      ;
extern INDEX gam_bInfiniteAmmo    ;
extern INDEX gam_bRespawnInPlace  ;
extern INDEX gam_bPlayEntireGame;
extern INDEX gam_bWeaponsStay;
extern INDEX gam_bFriendlyFire;
extern INDEX gam_iInitialMana;
extern INDEX gam_iQuickStartDifficulty;
extern INDEX gam_iQuickStartMode;
extern INDEX gam_bQuickStartMP;
extern INDEX gam_iStartDifficulty;
extern INDEX gam_iStartMode;
extern INDEX gam_iBlood;
extern INDEX gam_bGibs;
extern INDEX gam_bUseExtraEnemies;
extern CTString gam_strGameAgentExtras;
//###########################################################################################################	
//######################                       ST8VI MOD                          ###########################	
//###########################################################################################################
//Player.es
extern FLOAT st8_fDamageAmount;// = 0.01f; 			//0.2f;
extern FLOAT st8_fDirection;// = 1.5f;
extern FLOAT st8_fGravityDir;// = 30.0f;
extern FLOAT st8_fRegeneration;// = 5.0f;
extern INDEX st8_bEnableRegeneration;// = TRUE;
extern INDEX st8_bEnableExtGravity;// = TRUE;
extern INDEX st8_bEnableExtSpeed;// = FALSE;
extern FLOAT st8_fPlayerExtSpeed;// = 1.0f;
extern INDEX st8_bStickyfeet;// = FALSE;
//Projectile.es
extern FLOAT  st8_fRangeDamageAmount;// = 50.0f; // 75.0f;
extern FLOAT  st8_fRocketSpeed;// = -30.0f;
extern FLOAT  st8_fWalkerRocketSpeed;// = -30.0f;
extern FLOAT  st8_fWalkerWeaponMode;// = 0.0f;
extern FLOAT  st8_fPlayerLaserWeaponMode;// = 0.0f;
//PlayerWeapons.es 
extern FLOAT st8_fRocketDelay;// = 0.0f; // 0,05f
extern FLOAT st8_fRocketFireSpeed;// = 0.35f; // 0.05f
extern FLOAT st8_fColtPower;// = 10.0f; 
extern FLOAT st8_fLaserFireSpeed;// = 0.014f; //
extern FLOAT st8_fTompsonFireSpeed;// = 1.0f;
extern FLOAT st8_fSingleShotgunFireSpeed;// = 1.0f;
extern FLOAT st8_fDoubleShotgunFireSpeed;// = 1.0f;
extern FLOAT st8_fCannonFireSpeed;// = 1.0f;

extern FLOAT st8_fSingleShotgunPower;// = 1.0f;
extern FLOAT st8_fDoubleShotgunPower;// = 1.0f; 
extern FLOAT st8_fTommygunPower;// = 1.0f;
extern FLOAT st8_fMinigunPower;// = 1.0f; 
extern FLOAT st8_fRLauncherPower;// = 1.0f;
extern FLOAT st8_fGrenadesPower;// = 1.0f; 
extern FLOAT st8_fCannonPower;// = 1.0f;  

extern INDEX st8_bDisableCannon;// = FALSE;
extern INDEX st8_bDisableGrenades;// = FALSE;
extern INDEX st8_bDisableKnife;// = FALSE;
extern INDEX st8_bDisableChainSaw;// = FALSE;
extern INDEX st8_bDisableColt;// = FALSE;
extern INDEX st8_bDisableDoubleColt;// = FALSE;
extern INDEX st8_bDisableSingleShotgun;// = FALSE;
extern INDEX st8_bDisableDoubleShotgun;// = FALSE;
extern INDEX st8_bDisableTommygun;// = FALSE;
extern INDEX st8_bDisableMinigun;// = FALSE;
extern INDEX st8_bDisableFlamer;// = FALSE;
extern INDEX st8_bDisableLaser;// = FALSE;
extern INDEX st8_bDisableSniper;// = FALSE;
extern INDEX st8_bDisableRLauncher;// = FALSE;
extern INDEX st8_bDisableAllWeapons;// = FALSE;
extern INDEX st8_bGiveAllWeapons;// = FALSE;
// Game.cpp
extern INDEX st8_bModeHealth;// = 0;
extern INDEX st8_bEnableGhostBuster;// = 0;
extern INDEX st8_bEnablePipeBomb;// = 0;
//
extern INDEX rf_bRemovePowerups;// = 0;
extern INDEX rf_bRemoveSupers;// = 0;
extern INDEX rf_bRemoveCannon;// = 0;
extern INDEX rf_bRemoveGrenades;// = 0;
extern INDEX rf_bRemoveChainSaw;// = 0;
extern INDEX rf_bRemoveColt;// = 0;
//extern INDEX rf_bRemoveDoubleColt = 0;
extern INDEX rf_bRemoveSingleShotgun;// = 0;
extern INDEX rf_bRemoveDoubleShotgun;// = 0;
extern INDEX rf_bRemoveTommygun;// = 0;
extern INDEX rf_bRemoveMinigun;// = 0;
extern INDEX rf_bRemoveFlamer;// = 0;
extern INDEX rf_bRemoveLaser;// = 0;
extern INDEX rf_bRemoveSniper;// = 0;
extern INDEX rf_bRemoveRLauncher;// = 0;
//
extern INDEX rf_iMode;// = 0;
extern INDEX rf_bModifySpawners;// = 0;
extern FLOAT rf_fEnemySpawnerCountMultiplier;// = 1;
extern FLOAT rf_fEnemySpawnerGroupSizeMultiplier;// = 1;
extern FLOAT rf_fEnemySpawnerDelayMultiplier;// = 1;
extern FLOAT rf_fEnemySpawnerCircleMultiplier;// = 1;
extern INDEX rf_bChangeLights;// = 0;
extern INDEX rf_bRandomLights;// = 0;
//###########################################################################################################	
//###########################################################################################################	
//###########################################################################################################

static void SetGameModeParameters(CSessionProperties &sp)
{
  sp.sp_gmGameMode = (CSessionProperties::GameMode) Clamp(INDEX(gam_iStartMode), -1, 2);

  switch (sp.sp_gmGameMode) {
  default:
    ASSERT(FALSE);
  case CSessionProperties::GM_COOPERATIVE:
    sp.sp_ulSpawnFlags |= SPF_SINGLEPLAYER|SPF_COOPERATIVE;
    break;
  case CSessionProperties::GM_FLYOVER:
    sp.sp_ulSpawnFlags |= SPF_FLYOVER|SPF_MASK_DIFFICULTY;
    break;
  case CSessionProperties::GM_SCOREMATCH:
  case CSessionProperties::GM_FRAGMATCH:
    sp.sp_ulSpawnFlags |= SPF_DEATHMATCH;
    break;
  }
}
static void SetDifficultyParameters(CSessionProperties &sp)
{
  INDEX iDifficulty = gam_iStartDifficulty;
  if (iDifficulty==4) {
    sp.sp_bMental = TRUE;
    iDifficulty=2;
  } else {
    sp.sp_bMental = FALSE;
  }
  sp.sp_gdGameDifficulty = (CSessionProperties::GameDifficulty) Clamp(INDEX(iDifficulty), -1, 3);

  switch (sp.sp_gdGameDifficulty) {
  case CSessionProperties::GD_TOURIST:
    sp.sp_ulSpawnFlags = SPF_EASY;//SPF_TOURIST; !!!!
    sp.sp_fEnemyMovementSpeed = gam_afEnemyMovementSpeed [0];
    sp.sp_fEnemyAttackSpeed   = gam_afEnemyAttackSpeed   [0];
    sp.sp_fDamageStrength     = gam_afDamageStrength     [0];
    sp.sp_fAmmoQuantity       = gam_afAmmoQuantity       [0];
    break;
  case CSessionProperties::GD_EASY:
    sp.sp_ulSpawnFlags = SPF_EASY;
    sp.sp_fEnemyMovementSpeed = gam_afEnemyMovementSpeed [1];
    sp.sp_fEnemyAttackSpeed   = gam_afEnemyAttackSpeed   [1];
    sp.sp_fDamageStrength     = gam_afDamageStrength     [1];
    sp.sp_fAmmoQuantity       = gam_afAmmoQuantity       [1];
    break;
  default:
    ASSERT(FALSE);
  case CSessionProperties::GD_NORMAL:
    sp.sp_ulSpawnFlags = SPF_NORMAL;
    sp.sp_fEnemyMovementSpeed = gam_afEnemyMovementSpeed [2];
    sp.sp_fEnemyAttackSpeed   = gam_afEnemyAttackSpeed   [2];
    sp.sp_fDamageStrength     = gam_afDamageStrength     [2];
    sp.sp_fAmmoQuantity       = gam_afAmmoQuantity       [2];
    break;
  case CSessionProperties::GD_HARD:
    sp.sp_ulSpawnFlags = SPF_HARD;
    sp.sp_fEnemyMovementSpeed = gam_afEnemyMovementSpeed [3];
    sp.sp_fEnemyAttackSpeed   = gam_afEnemyAttackSpeed   [3];
    sp.sp_fDamageStrength     = gam_afDamageStrength     [3];
    sp.sp_fAmmoQuantity       = gam_afAmmoQuantity       [3];
    break;
  case CSessionProperties::GD_EXTREME:
    sp.sp_ulSpawnFlags = SPF_EXTREME;
    sp.sp_fEnemyMovementSpeed = gam_afEnemyMovementSpeed [4];
    sp.sp_fEnemyAttackSpeed   = gam_afEnemyAttackSpeed   [4];
    sp.sp_fDamageStrength     = gam_afDamageStrength     [4];
    sp.sp_fAmmoQuantity       = gam_afAmmoQuantity       [4];
    break;
  }
}

// set properties for a single player session
void CGame::SetSinglePlayerSession(CSessionProperties &sp)
{
  // clear
  memset(&sp, 0, sizeof(sp));

  SetDifficultyParameters(sp);
  SetGameModeParameters(sp);
  sp.sp_ulSpawnFlags&=~SPF_COOPERATIVE;

  sp.sp_bEndOfGame = FALSE;

  sp.sp_ctMaxPlayers = 1;
  sp.sp_bWaitAllPlayers = FALSE;
  sp.sp_bQuickTest = FALSE;
  sp.sp_bCooperative = TRUE;
  sp.sp_bSinglePlayer = TRUE;
  sp.sp_bUseFrags = FALSE;

  sp.sp_iScoreLimit = 0;
  sp.sp_iFragLimit  = 0; 
  sp.sp_iTimeLimit  = 0; 

  sp.sp_ctCredits     = 0;
  sp.sp_ctCreditsLeft = 0;
  sp.sp_tmSpawnInvulnerability = 0;

  sp.sp_bTeamPlay = FALSE;
  sp.sp_bFriendlyFire = FALSE;
  sp.sp_bWeaponsStay = FALSE;
  sp.sp_bPlayEntireGame = TRUE;

  sp.sp_bAmmoStays        = FALSE;
  sp.sp_bHealthArmorStays = FALSE;
  sp.sp_bAllowHealth = TRUE;
  sp.sp_bAllowArmor = TRUE;
  sp.sp_bInfiniteAmmo = FALSE;
  sp.sp_bRespawnInPlace = FALSE;
  sp.sp_fExtraEnemyStrength          = 0;
  sp.sp_fExtraEnemyStrengthPerPlayer = 0;

  sp.sp_iBlood = Clamp( gam_iBlood, 0, 3);
  sp.sp_bGibs  = gam_bGibs;
//###########################################################################################################	
//######################                       ST8VI MOD                          ###########################	
//###########################################################################################################

	sp.sp_st8_fDamageAmount = st8_fDamageAmount;
	sp.sp_st8_fDirection = st8_fDirection;
	sp.sp_st8_fGravityDir = st8_fGravityDir;
	sp.sp_st8_fRegeneration = st8_fRegeneration;
	sp.sp_st8_bEnableRegeneration = st8_bEnableRegeneration;
	sp.sp_st8_bEnableExtGravity = st8_bEnableExtGravity;
	sp.sp_st8_bEnableExtSpeed = st8_bEnableExtSpeed;
	sp.sp_st8_fPlayerExtSpeed = st8_fPlayerExtSpeed;
	sp.sp_st8_bStickyfeet = st8_bStickyfeet;
		
	sp.sp_st8_fRangeDamageAmount = st8_fRangeDamageAmount;
	sp.sp_st8_fRocketSpeed = st8_fRocketSpeed;
	sp.sp_st8_fWalkerRocketSpeed = st8_fWalkerRocketSpeed;
	sp.sp_st8_fWalkerWeaponMode = st8_fWalkerWeaponMode;
	sp.sp_st8_fPlayerLaserWeaponMode = st8_fPlayerLaserWeaponMode;
	
	sp.sp_st8_fRocketDelay = st8_fRocketDelay;
	sp.sp_st8_fRocketFireSpeed = st8_fRocketFireSpeed;
	sp.sp_st8_fColtPower = st8_fColtPower;
	sp.sp_st8_fLaserFireSpeed = st8_fLaserFireSpeed;
	sp.sp_st8_fSingleShotgunFireSpeed = st8_fSingleShotgunFireSpeed;
	sp.sp_st8_fDoubleShotgunFireSpeed = st8_fDoubleShotgunFireSpeed;
	sp.sp_st8_fCannonFireSpeed = st8_fCannonFireSpeed;
	sp.sp_st8_fTompsonFireSpeed = st8_fTompsonFireSpeed;

	sp.sp_st8_fSingleShotgunPower = st8_fSingleShotgunPower;
	sp.sp_st8_fDoubleShotgunPower = st8_fDoubleShotgunPower; 
	sp.sp_st8_fTommygunPower = st8_fTommygunPower;
	sp.sp_st8_fMinigunPower = st8_fMinigunPower; 
	sp.sp_st8_fRLauncherPower = st8_fRLauncherPower;
	sp.sp_st8_fGrenadesPower = st8_fGrenadesPower; 
	sp.sp_st8_fCannonPower = st8_fCannonPower; 
	
	sp.sp_st8_bDisableCannon = st8_bDisableCannon;
	sp.sp_st8_bDisableGrenades = st8_bDisableGrenades;
	sp.sp_st8_bDisableColt = st8_bDisableColt;
	sp.sp_st8_bDisableDoubleColt = st8_bDisableDoubleColt;
	sp.sp_st8_bDisableKnife = st8_bDisableKnife;
	sp.sp_st8_bDisableChainSaw = st8_bDisableChainSaw;
	sp.sp_st8_bDisableSingleShotgun = st8_bDisableSingleShotgun;
	sp.sp_st8_bDisableDoubleShotgun = st8_bDisableDoubleShotgun;
	sp.sp_st8_bDisableTommygun = st8_bDisableTommygun;
	sp.sp_st8_bDisableMinigun = st8_bDisableMinigun;
	sp.sp_st8_bDisableFlamer = st8_bDisableFlamer;
	sp.sp_st8_bDisableLaser = st8_bDisableLaser;
	sp.sp_st8_bDisableSniper = st8_bDisableSniper;
	sp.sp_st8_bDisableRLauncher = st8_bDisableRLauncher;
	sp.sp_st8_bDisableAllWeapons = st8_bDisableAllWeapons;
	sp.sp_st8_bGiveAllWeapons = st8_bGiveAllWeapons;
 
// Game.cpp
	sp.sp_rf_bRemovePowerups = rf_bRemovePowerups;
	sp.sp_rf_bRemoveSupers = rf_bRemoveSupers;
	
	sp.sp_rf_bRemoveCannon = rf_bRemoveCannon;
	sp.sp_rf_bRemoveGrenades = rf_bRemoveGrenades;
	sp.sp_rf_bRemoveChainSaw = rf_bRemoveChainSaw;
	sp.sp_rf_bRemoveColt = rf_bRemoveColt;
	//sp.sp_rf_bRemoveDoubleColt = rf_bRemoveDoubleColt;
	sp.sp_rf_bRemoveSingleShotgun = rf_bRemoveSingleShotgun;
	sp.sp_rf_bRemoveDoubleShotgun = rf_bRemoveDoubleShotgun;
	sp.sp_rf_bRemoveTommygun = rf_bRemoveTommygun;
	sp.sp_rf_bRemoveMinigun = rf_bRemoveMinigun;
	sp.sp_rf_bRemoveFlamer = rf_bRemoveFlamer;
	sp.sp_rf_bRemoveLaser = rf_bRemoveLaser;
	sp.sp_rf_bRemoveSniper = rf_bRemoveSniper;
	sp.sp_rf_bRemoveRLauncher = rf_bRemoveRLauncher;
	//
	sp.sp_st8_bModeHealth = st8_bModeHealth;
	sp.sp_st8_bEnableGhostBuster = st8_bEnableGhostBuster;
	sp.sp_st8_bEnablePipeBomb = st8_bEnablePipeBomb;
	//
	sp.sp_rf_iMode = rf_iMode;
	
	sp.sp_rf_bModifySpawners = rf_bModifySpawners;
	sp.sp_rf_fEnemySpawnerCountMultiplier = rf_fEnemySpawnerCountMultiplier;
	sp.sp_rf_fEnemySpawnerGroupSizeMultiplier = rf_fEnemySpawnerGroupSizeMultiplier;
	sp.sp_rf_fEnemySpawnerDelayMultiplier = rf_fEnemySpawnerDelayMultiplier;
	sp.sp_rf_fEnemySpawnerCircleMultiplier = rf_fEnemySpawnerCircleMultiplier;
	
	sp.sp_rf_bChangeLights = rf_bChangeLights;
	sp.sp_rf_bRandomLights = rf_bRandomLights;
//###########################################################################################################	
//###########################################################################################################	
//###########################################################################################################  
}

// set properties for a quick start session
void CGame::SetQuickStartSession(CSessionProperties &sp)
{
  gam_iStartDifficulty = gam_iQuickStartDifficulty;
  gam_iStartMode = gam_iQuickStartMode;

  // same as single player
  if (!gam_bQuickStartMP) {
    SetSinglePlayerSession(sp);
  } else {
    SetMultiPlayerSession(sp);
  }
  // quick start type
  sp.sp_bQuickTest = TRUE;
//###########################################################################################################	
//######################                       ST8VI MOD                          ###########################	
//###########################################################################################################

	sp.sp_st8_fDamageAmount = st8_fDamageAmount;
	sp.sp_st8_fDirection = st8_fDirection;
	sp.sp_st8_fGravityDir = st8_fGravityDir;
	sp.sp_st8_fRegeneration = st8_fRegeneration;
	sp.sp_st8_bEnableRegeneration = st8_bEnableRegeneration;
	sp.sp_st8_bEnableExtGravity = st8_bEnableExtGravity;
	sp.sp_st8_bEnableExtSpeed = st8_bEnableExtSpeed;
	sp.sp_st8_fPlayerExtSpeed = st8_fPlayerExtSpeed;
	sp.sp_st8_bStickyfeet = st8_bStickyfeet;
		
	sp.sp_st8_fRangeDamageAmount = st8_fRangeDamageAmount;
	sp.sp_st8_fRocketSpeed = st8_fRocketSpeed;
	sp.sp_st8_fWalkerRocketSpeed = st8_fWalkerRocketSpeed;
	sp.sp_st8_fWalkerWeaponMode = st8_fWalkerWeaponMode;
	sp.sp_st8_fPlayerLaserWeaponMode = st8_fPlayerLaserWeaponMode;
	
	sp.sp_st8_fRocketDelay = st8_fRocketDelay;
	sp.sp_st8_fRocketFireSpeed = st8_fRocketFireSpeed;
	sp.sp_st8_fColtPower = st8_fColtPower;
	sp.sp_st8_fLaserFireSpeed = st8_fLaserFireSpeed;
	sp.sp_st8_fSingleShotgunFireSpeed = st8_fSingleShotgunFireSpeed;
	sp.sp_st8_fDoubleShotgunFireSpeed = st8_fDoubleShotgunFireSpeed;
	sp.sp_st8_fCannonFireSpeed = st8_fCannonFireSpeed;
	sp.sp_st8_fTompsonFireSpeed = st8_fTompsonFireSpeed;

	sp.sp_st8_fSingleShotgunPower = st8_fSingleShotgunPower;
	sp.sp_st8_fDoubleShotgunPower = st8_fDoubleShotgunPower; 
	sp.sp_st8_fTommygunPower = st8_fTommygunPower;
	sp.sp_st8_fMinigunPower = st8_fMinigunPower; 
	sp.sp_st8_fRLauncherPower = st8_fRLauncherPower;
	sp.sp_st8_fGrenadesPower = st8_fGrenadesPower; 
	sp.sp_st8_fCannonPower = st8_fCannonPower; 
	
	sp.sp_st8_bDisableCannon = st8_bDisableCannon;
	sp.sp_st8_bDisableGrenades = st8_bDisableGrenades;
	sp.sp_st8_bDisableColt = st8_bDisableColt;
	sp.sp_st8_bDisableDoubleColt = st8_bDisableDoubleColt;
	sp.sp_st8_bDisableKnife = st8_bDisableKnife;
	sp.sp_st8_bDisableChainSaw = st8_bDisableChainSaw;
	sp.sp_st8_bDisableSingleShotgun = st8_bDisableSingleShotgun;
	sp.sp_st8_bDisableDoubleShotgun = st8_bDisableDoubleShotgun;
	sp.sp_st8_bDisableTommygun = st8_bDisableTommygun;
	sp.sp_st8_bDisableMinigun = st8_bDisableMinigun;
	sp.sp_st8_bDisableFlamer = st8_bDisableFlamer;
	sp.sp_st8_bDisableLaser = st8_bDisableLaser;
	sp.sp_st8_bDisableSniper = st8_bDisableSniper;
	sp.sp_st8_bDisableRLauncher = st8_bDisableRLauncher;
	sp.sp_st8_bDisableAllWeapons = st8_bDisableAllWeapons;
	sp.sp_st8_bGiveAllWeapons = st8_bGiveAllWeapons;
 
// Game.cpp
	sp.sp_rf_bRemovePowerups = rf_bRemovePowerups;
	sp.sp_rf_bRemoveSupers = rf_bRemoveSupers;
	
	sp.sp_rf_bRemoveCannon = rf_bRemoveCannon;
	sp.sp_rf_bRemoveGrenades = rf_bRemoveGrenades;
	sp.sp_rf_bRemoveChainSaw = rf_bRemoveChainSaw;
	sp.sp_rf_bRemoveColt = rf_bRemoveColt;
	//sp.sp_rf_bRemoveDoubleColt = rf_bRemoveDoubleColt;
	sp.sp_rf_bRemoveSingleShotgun = rf_bRemoveSingleShotgun;
	sp.sp_rf_bRemoveDoubleShotgun = rf_bRemoveDoubleShotgun;
	sp.sp_rf_bRemoveTommygun = rf_bRemoveTommygun;
	sp.sp_rf_bRemoveMinigun = rf_bRemoveMinigun;
	sp.sp_rf_bRemoveFlamer = rf_bRemoveFlamer;
	sp.sp_rf_bRemoveLaser = rf_bRemoveLaser;
	sp.sp_rf_bRemoveSniper = rf_bRemoveSniper;
	sp.sp_rf_bRemoveRLauncher = rf_bRemoveRLauncher;
	//
	sp.sp_st8_bModeHealth = st8_bModeHealth;
	sp.sp_st8_bEnableGhostBuster = st8_bEnableGhostBuster;
	sp.sp_st8_bEnablePipeBomb = st8_bEnablePipeBomb;
	//
	sp.sp_rf_iMode = rf_iMode;
	
	sp.sp_rf_bModifySpawners = rf_bModifySpawners;
	sp.sp_rf_fEnemySpawnerCountMultiplier = rf_fEnemySpawnerCountMultiplier;
	sp.sp_rf_fEnemySpawnerGroupSizeMultiplier = rf_fEnemySpawnerGroupSizeMultiplier;
	sp.sp_rf_fEnemySpawnerDelayMultiplier = rf_fEnemySpawnerDelayMultiplier;
	sp.sp_rf_fEnemySpawnerCircleMultiplier = rf_fEnemySpawnerCircleMultiplier;
	
	sp.sp_rf_bChangeLights = rf_bChangeLights;
	sp.sp_rf_bRandomLights = rf_bRandomLights;
//###########################################################################################################	
//###########################################################################################################	
//###########################################################################################################
}

// set properties for a multiplayer session
void CGame::SetMultiPlayerSession(CSessionProperties &sp)
{
  // clear
  memset(&sp, 0, sizeof(sp));

  SetDifficultyParameters(sp);
  SetGameModeParameters(sp);
  sp.sp_ulSpawnFlags&=~SPF_SINGLEPLAYER;

  sp.sp_bEndOfGame = FALSE;

  sp.sp_bQuickTest = FALSE;
  sp.sp_bCooperative = sp.sp_gmGameMode==CSessionProperties::GM_COOPERATIVE;
  sp.sp_bSinglePlayer = FALSE;
  sp.sp_bPlayEntireGame = gam_bPlayEntireGame;
  sp.sp_bUseFrags = sp.sp_gmGameMode==CSessionProperties::GM_FRAGMATCH;
  sp.sp_bWeaponsStay = gam_bWeaponsStay;
  sp.sp_bFriendlyFire = gam_bFriendlyFire;
  sp.sp_ctMaxPlayers = gam_ctMaxPlayers;
  sp.sp_bWaitAllPlayers = gam_bWaitAllPlayers;

  sp.sp_bAmmoStays        = gam_bAmmoStays       ;
  sp.sp_bHealthArmorStays = gam_bHealthArmorStays;
  sp.sp_bAllowHealth      = gam_bAllowHealth     ;
  sp.sp_bAllowArmor       = gam_bAllowArmor      ;
  sp.sp_bInfiniteAmmo     = gam_bInfiniteAmmo    ;
  sp.sp_bRespawnInPlace   = gam_bRespawnInPlace  ;

  sp.sp_fManaTransferFactor = gam_fManaTransferFactor;
  sp.sp_fExtraEnemyStrength          = gam_fExtraEnemyStrength         ;
  sp.sp_fExtraEnemyStrengthPerPlayer = gam_fExtraEnemyStrengthPerPlayer;
  sp.sp_iInitialMana        = gam_iInitialMana;

  sp.sp_iBlood = Clamp( gam_iBlood, 0, 3);
  sp.sp_bGibs  = gam_bGibs;
  sp.sp_tmSpawnInvulnerability = gam_tmSpawnInvulnerability;

  sp.sp_bUseExtraEnemies = gam_bUseExtraEnemies;
//###########################################################################################################	
//######################                       ST8VI MOD                          ###########################	
//###########################################################################################################

	sp.sp_st8_fDamageAmount = st8_fDamageAmount;
	sp.sp_st8_fDirection = st8_fDirection;
	sp.sp_st8_fGravityDir = st8_fGravityDir;
	sp.sp_st8_fRegeneration = st8_fRegeneration;
	sp.sp_st8_bEnableRegeneration = st8_bEnableRegeneration;
	sp.sp_st8_bEnableExtGravity = st8_bEnableExtGravity;
	sp.sp_st8_bEnableExtSpeed = st8_bEnableExtSpeed;
	sp.sp_st8_fPlayerExtSpeed = st8_fPlayerExtSpeed;
	sp.sp_st8_bStickyfeet = st8_bStickyfeet;
		
	sp.sp_st8_fRangeDamageAmount = st8_fRangeDamageAmount;
	sp.sp_st8_fRocketSpeed = st8_fRocketSpeed;
	sp.sp_st8_fWalkerRocketSpeed = st8_fWalkerRocketSpeed;
	sp.sp_st8_fWalkerWeaponMode = st8_fWalkerWeaponMode;
	sp.sp_st8_fPlayerLaserWeaponMode = st8_fPlayerLaserWeaponMode;
	
	sp.sp_st8_fRocketDelay = st8_fRocketDelay;
	sp.sp_st8_fRocketFireSpeed = st8_fRocketFireSpeed;
	sp.sp_st8_fColtPower = st8_fColtPower;
	sp.sp_st8_fLaserFireSpeed = st8_fLaserFireSpeed;
	sp.sp_st8_fSingleShotgunFireSpeed = st8_fSingleShotgunFireSpeed;
	sp.sp_st8_fDoubleShotgunFireSpeed = st8_fDoubleShotgunFireSpeed;
	sp.sp_st8_fCannonFireSpeed = st8_fCannonFireSpeed;
	sp.sp_st8_fTompsonFireSpeed = st8_fTompsonFireSpeed;

	sp.sp_st8_fSingleShotgunPower = st8_fSingleShotgunPower;
	sp.sp_st8_fDoubleShotgunPower = st8_fDoubleShotgunPower; 
	sp.sp_st8_fTommygunPower = st8_fTommygunPower;
	sp.sp_st8_fMinigunPower = st8_fMinigunPower; 
	sp.sp_st8_fRLauncherPower = st8_fRLauncherPower;
	sp.sp_st8_fGrenadesPower = st8_fGrenadesPower; 
	sp.sp_st8_fCannonPower = st8_fCannonPower; 
	
	sp.sp_st8_bDisableCannon = st8_bDisableCannon;
	sp.sp_st8_bDisableGrenades = st8_bDisableGrenades;
	sp.sp_st8_bDisableColt = st8_bDisableColt;
	sp.sp_st8_bDisableDoubleColt = st8_bDisableDoubleColt;
	sp.sp_st8_bDisableKnife = st8_bDisableKnife;
	sp.sp_st8_bDisableChainSaw = st8_bDisableChainSaw;
	sp.sp_st8_bDisableSingleShotgun = st8_bDisableSingleShotgun;
	sp.sp_st8_bDisableDoubleShotgun = st8_bDisableDoubleShotgun;
	sp.sp_st8_bDisableTommygun = st8_bDisableTommygun;
	sp.sp_st8_bDisableMinigun = st8_bDisableMinigun;
	sp.sp_st8_bDisableFlamer = st8_bDisableFlamer;
	sp.sp_st8_bDisableLaser = st8_bDisableLaser;
	sp.sp_st8_bDisableSniper = st8_bDisableSniper;
	sp.sp_st8_bDisableRLauncher = st8_bDisableRLauncher;
	sp.sp_st8_bDisableAllWeapons = st8_bDisableAllWeapons;
	sp.sp_st8_bGiveAllWeapons = st8_bGiveAllWeapons;
 
// Game.cpp
	sp.sp_rf_bRemovePowerups = rf_bRemovePowerups;
	sp.sp_rf_bRemoveSupers = rf_bRemoveSupers;
	
	sp.sp_rf_bRemoveCannon = rf_bRemoveCannon;
	sp.sp_rf_bRemoveGrenades = rf_bRemoveGrenades;
	sp.sp_rf_bRemoveChainSaw = rf_bRemoveChainSaw;
	sp.sp_rf_bRemoveColt = rf_bRemoveColt;
	//sp.sp_rf_bRemoveDoubleColt = rf_bRemoveDoubleColt;
	sp.sp_rf_bRemoveSingleShotgun = rf_bRemoveSingleShotgun;
	sp.sp_rf_bRemoveDoubleShotgun = rf_bRemoveDoubleShotgun;
	sp.sp_rf_bRemoveTommygun = rf_bRemoveTommygun;
	sp.sp_rf_bRemoveMinigun = rf_bRemoveMinigun;
	sp.sp_rf_bRemoveFlamer = rf_bRemoveFlamer;
	sp.sp_rf_bRemoveLaser = rf_bRemoveLaser;
	sp.sp_rf_bRemoveSniper = rf_bRemoveSniper;
	sp.sp_rf_bRemoveRLauncher = rf_bRemoveRLauncher;
	//
	sp.sp_st8_bModeHealth = st8_bModeHealth;
	sp.sp_st8_bEnableGhostBuster = st8_bEnableGhostBuster;
	sp.sp_st8_bEnablePipeBomb = st8_bEnablePipeBomb;
	//
	sp.sp_rf_iMode = rf_iMode;
	
	sp.sp_rf_bModifySpawners = rf_bModifySpawners;
	sp.sp_rf_fEnemySpawnerCountMultiplier = rf_fEnemySpawnerCountMultiplier;
	sp.sp_rf_fEnemySpawnerGroupSizeMultiplier = rf_fEnemySpawnerGroupSizeMultiplier;
	sp.sp_rf_fEnemySpawnerDelayMultiplier = rf_fEnemySpawnerDelayMultiplier;
	sp.sp_rf_fEnemySpawnerCircleMultiplier = rf_fEnemySpawnerCircleMultiplier;
	
	sp.sp_rf_bChangeLights = rf_bChangeLights;
	sp.sp_rf_bRandomLights = rf_bRandomLights;
//###########################################################################################################	
//###########################################################################################################	
//###########################################################################################################
  // set credits and limits
  if (sp.sp_bCooperative) {
    sp.sp_ctCredits     = gam_iCredits;
    sp.sp_ctCreditsLeft = gam_iCredits;
    sp.sp_iScoreLimit = 0;
    sp.sp_iFragLimit  = 0;
    sp.sp_iTimeLimit  = 0;
    sp.sp_bAllowHealth = TRUE;
    sp.sp_bAllowArmor  = TRUE;

  } else {
    sp.sp_ctCredits     = -1;
    sp.sp_ctCreditsLeft = -1;
    sp.sp_iScoreLimit = gam_iScoreLimit;
    sp.sp_iFragLimit  = gam_iFragLimit;
    sp.sp_iTimeLimit  = gam_iTimeLimit;
    sp.sp_bWeaponsStay = FALSE;
    sp.sp_bAmmoStays = FALSE;
    sp.sp_bHealthArmorStays = FALSE;
    if (sp.sp_bUseFrags) {
      sp.sp_iScoreLimit = 0;
    } else {
      sp.sp_iFragLimit = 0;
    }
  }
}

BOOL IsMenuEnabled_(const CTString &strMenuName)
{
  if (strMenuName=="Single Player") {
    return TRUE;
  } else if (strMenuName=="Network"      ) {
    return TRUE;
  } else if (strMenuName=="Split Screen" ) {
    return FALSE;
  } else if (strMenuName=="High Score"   ) {
    return FALSE;
  } else if (strMenuName=="Training"   ) {
    return FALSE;
  } else if (strMenuName=="Technology Test") {
    return TRUE;
  } else {
    return TRUE;
  }
}
BOOL IsMenuEnabledCfunc(void* pArgs)
{
  CTString strMenuName = *NEXTARGUMENT(CTString*);
  return IsMenuEnabled_(strMenuName);
}

CTString GetGameTypeName(INDEX iMode)
{
  switch (iMode) {
  default:
    return "";
    break;
  case CSessionProperties::GM_COOPERATIVE:
    return TRANS("Cooperative");
    break;
  case CSessionProperties::GM_FLYOVER:
    return TRANS("Flyover");
    break;
  case CSessionProperties::GM_SCOREMATCH:
    return TRANS("Scorematch");
    break;
  case CSessionProperties::GM_FRAGMATCH:
    return TRANS("Fragmatch");
    break;
  }
}
CTString GetGameTypeNameCfunc(void* pArgs)
{
  INDEX iMode = NEXTARGUMENT(INDEX);
  return GetGameTypeName(iMode);
}
CTString GetCurrentGameTypeName()
{
  const CSessionProperties &sp = *GetSP();
  return GetGameTypeName(sp.sp_gmGameMode);
}

CTString GetGameAgentRulesInfo(void)
{
  CTString strOut;
  CTString strKey;
  const CSessionProperties &sp = *GetSP();

  CTString strDifficulty;
  if (sp.sp_bMental) {
    strDifficulty = TRANS("Mental");
  } else {
    switch(sp.sp_gdGameDifficulty) {
    case CSessionProperties::GD_TOURIST:
      strDifficulty = TRANS("Tourist");
      break;
    case CSessionProperties::GD_EASY:
      strDifficulty = TRANS("Easy");
      break;
    default:
      ASSERT(FALSE);
    case CSessionProperties::GD_NORMAL:
      strDifficulty = TRANS("Normal");
      break;
    case CSessionProperties::GD_HARD:
      strDifficulty = TRANS("Hard");
      break;
    case CSessionProperties::GD_EXTREME:
      strDifficulty = TRANS("Serious");
      break;
    }
  }

  strKey.PrintF(";difficulty;%s", (const char*)strDifficulty);
  strOut+=strKey;

  strKey.PrintF(";friendlyfire;%d", sp.sp_bFriendlyFire?0:1);
  strOut+=strKey;

  strKey.PrintF(";weaponsstay;%d", sp.sp_bWeaponsStay?0:1);
  strOut+=strKey;

  strKey.PrintF(";ammostays;%d", sp.sp_bAmmoStays                   ?0:1);	strOut+=strKey;
  strKey.PrintF(";healthandarmorstays;%d", sp.sp_bHealthArmorStays  ?0:1);	strOut+=strKey;
  strKey.PrintF(";allowhealth;%d", sp.sp_bAllowHealth               ?0:1);	strOut+=strKey;
  strKey.PrintF(";allowarmor;%d", sp.sp_bAllowArmor                 ?0:1);	strOut+=strKey;
  strKey.PrintF(";infiniteammo;%d", sp.sp_bInfiniteAmmo             ?0:1);	strOut+=strKey;
  strKey.PrintF(";respawninplace;%d", sp.sp_bRespawnInPlace         ?0:1);	strOut+=strKey;

  if (sp.sp_bCooperative) {
    if (sp.sp_ctCredits<0) {
      strKey.PrintF(";credits;infinite");
      strOut+=strKey;
    } else if (sp.sp_ctCredits>0) {
      strKey.PrintF(";credits;%d", sp.sp_ctCredits);
      strOut+=strKey;
      strKey.PrintF(";credits_left;%d", sp.sp_ctCreditsLeft);
      strOut+=strKey;
    }
  } else {
    if (sp.sp_bUseFrags && sp.sp_iFragLimit>0) {
      strKey.PrintF(";fraglimit;%d", sp.sp_iFragLimit);
      strOut+=strKey;
    }
    if (!sp.sp_bUseFrags && sp.sp_iScoreLimit>0) {
      strKey.PrintF(";fraglimit;%d", sp.sp_iScoreLimit);
      strOut+=strKey;
    }
    if (sp.sp_iTimeLimit>0) {
      strKey.PrintF(";timelimit;%d", sp.sp_iTimeLimit);
      strOut+=strKey;
    }
  }

  // Don't mess with malicious code
  strOut+=gam_strGameAgentExtras;
  return strOut;
}

ULONG GetSpawnFlagsForGameType(INDEX iGameType)
{
  switch(iGameType) {
  default:
    ASSERT(FALSE);
  case CSessionProperties::GM_COOPERATIVE:  return SPF_COOPERATIVE;
  case CSessionProperties::GM_SCOREMATCH:   return SPF_DEATHMATCH;
  case CSessionProperties::GM_FRAGMATCH:    return SPF_DEATHMATCH;
  };
}
ULONG GetSpawnFlagsForGameTypeCfunc(void* pArgs)
{
  INDEX iGameType = NEXTARGUMENT(INDEX);
  return GetSpawnFlagsForGameType(iGameType);
}

