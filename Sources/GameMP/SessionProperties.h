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

/*
 * Class responsible for describing game session
 */
class CSessionProperties {
public:
  enum GameMode {
    GM_FLYOVER = -1,
    GM_COOPERATIVE = 0,
    GM_SCOREMATCH,
    GM_FRAGMATCH,
  };
  enum GameDifficulty {
    GD_TOURIST = -1,
    GD_EASY = 0,
    GD_NORMAL,
    GD_HARD,
    GD_EXTREME,
  };

  INDEX sp_ctMaxPlayers;    // maximum number of players in game
  BOOL sp_bWaitAllPlayers;  // wait for all players to connect
  BOOL sp_bQuickTest;       // set when game is tested from wed
  BOOL sp_bCooperative;     // players are not intended to kill each other
  BOOL sp_bSinglePlayer;    // single player mode has some special rules
  BOOL sp_bUseFrags;        // set if frags matter instead of score

  enum GameMode sp_gmGameMode;    // general game rules

  enum GameDifficulty sp_gdGameDifficulty;
  ULONG sp_ulSpawnFlags;
  BOOL sp_bMental;            // set if mental mode engaged

  INDEX sp_iScoreLimit;       // stop game after a player/team reaches given score
  INDEX sp_iFragLimit;        // stop game after a player/team reaches given score
  INDEX sp_iTimeLimit;        // stop game after given number of minutes elapses

  BOOL sp_bTeamPlay;          // players are divided in teams
  BOOL sp_bFriendlyFire;      // can harm player of same team
  BOOL sp_bWeaponsStay;       // weapon items do not dissapear when picked-up
  BOOL sp_bAmmoStays;         // ammo items do not dissapear when picked-up
  BOOL sp_bHealthArmorStays;  // health/armor items do exist
  BOOL sp_bPlayEntireGame;    // don't finish after one level in coop
  BOOL sp_bAllowHealth;       // health items do exist
  BOOL sp_bAllowArmor;        // armor items do exist
  BOOL sp_bInfiniteAmmo;      // ammo is not consumed when firing
  BOOL sp_bRespawnInPlace;    // players respawn on the place where they were killed, not on markers (coop only)

  FLOAT sp_fEnemyMovementSpeed; // enemy speed multiplier
  FLOAT sp_fEnemyAttackSpeed;   // enemy speed multiplier
  FLOAT sp_fDamageStrength;     // multiplier when damaged
  FLOAT sp_fAmmoQuantity;       // multiplier when picking up ammo
  FLOAT sp_fManaTransferFactor; // multiplier for the killed player mana that is to be added to killer's mana
  INDEX sp_iInitialMana;        // life price (mana that each player'll have upon respawning)
  FLOAT sp_fExtraEnemyStrength;            // fixed adder for extra enemy power 
  FLOAT sp_fExtraEnemyStrengthPerPlayer;   // adder for extra enemy power per each player playing

  INDEX sp_ctCredits;           // number of credits for this game
  INDEX sp_ctCreditsLeft;       // number of credits left on this level
  FLOAT sp_tmSpawnInvulnerability;   // how many seconds players are invunerable after respawning

  INDEX sp_iBlood;         // blood/gibs type (0=none, 1=green, 2=red, 3=hippie)
  BOOL  sp_bGibs;          // enable/disable gibbing

  BOOL  sp_bEndOfGame;     // marked when dm game is finished (any of the limits reached)

  ULONG sp_ulLevelsMask;    // mask of visited levels so far

  BOOL  sp_bUseExtraEnemies;  // spawn extra multiplayer enemies
  
//###########################################################################################################	
//######################                       ST8VI MOD                          ###########################	
//###########################################################################################################
//Player.es
 FLOAT sp_st8_fDamageAmount;
 FLOAT sp_st8_fDirection;
 FLOAT sp_st8_fGravityDir;
 FLOAT sp_st8_fRegeneration;
 INDEX sp_st8_bEnableRegeneration;
 INDEX sp_st8_bEnableExtGravity;
 INDEX sp_st8_bEnableExtSpeed;
 FLOAT sp_st8_fPlayerExtSpeed;
 INDEX sp_st8_bStickyfeet;
//Projectile.es
 FLOAT  sp_st8_fRangeDamageAmount;
 FLOAT  sp_st8_fRocketSpeed;
 FLOAT  sp_st8_fWalkerRocketSpeed;
 FLOAT  sp_st8_fWalkerWeaponMode;
 FLOAT  sp_st8_fPlayerLaserWeaponMode;
//PlayerWeapons.es 
 FLOAT sp_st8_fRocketDelay;
 FLOAT sp_st8_fRocketFireSpeed;
 FLOAT sp_st8_fColtPower;
 FLOAT sp_st8_fLaserFireSpeed;
 FLOAT sp_st8_fSingleShotgunFireSpeed;
 FLOAT sp_st8_fDoubleShotgunFireSpeed;
 FLOAT sp_st8_fCannonFireSpeed;
 FLOAT sp_st8_fTompsonFireSpeed;

 FLOAT sp_st8_fSingleShotgunPower;
 FLOAT sp_st8_fDoubleShotgunPower; 
 FLOAT sp_st8_fTommygunPower;
 FLOAT sp_st8_fMinigunPower; 
 FLOAT sp_st8_fRLauncherPower;
 FLOAT sp_st8_fGrenadesPower; 
 FLOAT sp_st8_fCannonPower;  
 
 INDEX sp_st8_bDisableCannon;
 INDEX sp_st8_bDisableGrenades;
 INDEX sp_st8_bDisableColt;
 INDEX sp_st8_bDisableDoubleColt; 
 INDEX sp_st8_bDisableKnife;
 INDEX sp_st8_bDisableChainSaw;
 INDEX sp_st8_bDisableSingleShotgun;
 INDEX sp_st8_bDisableDoubleShotgun;
 INDEX sp_st8_bDisableTommygun;
 INDEX sp_st8_bDisableMinigun;
 INDEX sp_st8_bDisableFlamer;
 INDEX sp_st8_bDisableLaser;
 INDEX sp_st8_bDisableSniper;
 INDEX sp_st8_bDisableRLauncher;
 INDEX sp_st8_bDisableAllWeapons;
 INDEX sp_st8_bGiveAllWeapons;
 
// Game.cpp
 INDEX sp_rf_bRemoveSupers;
 INDEX sp_rf_bRemovePowerups;
 INDEX sp_rf_bRemoveCannon;
 INDEX sp_rf_bRemoveGrenades;
 INDEX sp_rf_bRemoveChainSaw;
 INDEX sp_rf_bRemoveColt;
 //INDEX sp_rf_bRemoveDoubleColt; 
 INDEX sp_rf_bRemoveSingleShotgun;
 INDEX sp_rf_bRemoveDoubleShotgun;
 INDEX sp_rf_bRemoveTommygun;
 INDEX sp_rf_bRemoveMinigun;
 INDEX sp_rf_bRemoveFlamer;
 INDEX sp_rf_bRemoveLaser;
 INDEX sp_rf_bRemoveSniper;
 INDEX sp_rf_bRemoveRLauncher;
 //
 INDEX sp_st8_bModeHealth;
 INDEX sp_st8_bEnableGhostBuster;
 INDEX sp_st8_bEnablePipeBomb;
 //
 INDEX sp_rf_iMode;
 
 INDEX sp_rf_bModifySpawners;
 FLOAT sp_rf_fEnemySpawnerCountMultiplier;

 FLOAT sp_rf_fEnemySpawnerGroupSizeMultiplier;
 FLOAT sp_rf_fEnemySpawnerDelayMultiplier;
 FLOAT sp_rf_fEnemySpawnerCircleMultiplier;
 
 INDEX sp_rf_bChangeLights;
 INDEX sp_rf_bRandomLights;
//###########################################################################################################	
//###########################################################################################################	
//###########################################################################################################  
  
};

// NOTE: never instantiate CSessionProperties, as its size is not fixed to the size defined in engine
// use CUniversalSessionProperties for instantiating an object
class CUniversalSessionProperties {
public:
  union {
    CSessionProperties usp_sp;
    UBYTE usp_aubDummy[NET_MAXSESSIONPROPERTIES];
  };

  // must have exact the size as allocated block in engine
  CUniversalSessionProperties() { 
    ASSERT(sizeof(CSessionProperties)<=NET_MAXSESSIONPROPERTIES); 
    ASSERT(sizeof(CUniversalSessionProperties)==NET_MAXSESSIONPROPERTIES); 
    memset(usp_aubDummy, '\0', sizeof (usp_aubDummy));
  }
  operator CSessionProperties&(void) { return usp_sp; }
};

