#pragma once
#include <dll.h>
#include <BWAPI/UnaryFilter.h>
#include <BWAPI/ComparisonFilter.h>
#include <BWAPI/BestFilter.h>
#include <BWAPI/UnitSizeType.h>
#include <BWAPI/UpgradeType.h>
#include <BWAPI/WeaponType.h>
#include <BWAPI/Order.h>
#include <BWAPI/Race.h>

namespace BWAPI
{
  // forwards
  class PlayerInterface;
  typedef PlayerInterface *Player;
  class UnitType;
  class UnitInterface;
  typedef UnitInterface *Unit;

  // typedefs
  typedef UnaryFilter<Unit > UnitFilter;
  typedef UnaryFilter<Unit ,bool (*)(Unit )> PtrUnitFilter;
  typedef BestFilter<Unit >  BestUnitFilter;
  typedef CompareFilter<Unit ,int,int(*)(Unit )> PtrIntCompareUnitFilter;

  DLLEXPORT_TEMPLATE template class DLLEXPORT UnaryFilter<Unit >;
  DLLEXPORT_TEMPLATE template class DLLEXPORT UnaryFilter<UnitInterface* ,std::function<bool(UnitInterface*)>>;
  DLLEXPORT_TEMPLATE template class DLLEXPORT BestFilter<Unit >;
  DLLEXPORT_TEMPLATE template class DLLEXPORT CompareFilter<Unit ,int,int(*)(Unit )>;

  namespace Filter
  {
    /// <summary>A unary filter that checks if the unit type is a transport.</summary>
    DLLEXPORT extern const PtrUnitFilter IsTransport;

    /// @see BWAPI::UnitType::canProduce
    DLLEXPORT extern const PtrUnitFilter CanProduce;

    /// @see BWAPI::UnitType::canAttack
    DLLEXPORT extern const PtrUnitFilter CanAttack;

    /// @see BWAPI::UnitType::canMove
    DLLEXPORT extern const PtrUnitFilter CanMove;

    /// @see BWAPI::UnitType::isFlying
    DLLEXPORT extern const PtrUnitFilter IsFlyer;

    /// @see BWAPI::UnitInterface::IsFlying
    DLLEXPORT extern const PtrUnitFilter IsFlying;

    /// @see BWAPI::UnitType::regeneratesHP
    DLLEXPORT extern const PtrUnitFilter RegeneratesHP;

    /// @see BWAPI::UnitType::isSpellcaster
    DLLEXPORT extern const PtrUnitFilter IsSpellcaster;
    
    /// @see BWAPI::UnitType::hasPermanentCloak
    DLLEXPORT extern const PtrUnitFilter HasPermanentCloak;

    /// @see BWAPI::UnitType::isOrganic
    DLLEXPORT extern const PtrUnitFilter IsOrganic;

    /// @see BWAPI::UnitType::isMechanical
    DLLEXPORT extern const PtrUnitFilter IsMechanical;

    /// @see BWAPI::UnitType::isRobotic
    DLLEXPORT extern const PtrUnitFilter IsRobotic;

    /// @see BWAPI::UnitType::isDetector
    DLLEXPORT extern const PtrUnitFilter IsDetector;

    /// @see BWAPI::UnitType::isResourceContainer
    DLLEXPORT extern const PtrUnitFilter IsResourceContainer;

    /// @see BWAPI::UnitType::isResourceDepot
    DLLEXPORT extern const PtrUnitFilter IsResourceDepot;

    /// @see BWAPI::UnitType::isRefinery
    DLLEXPORT extern const PtrUnitFilter IsRefinery;

    /// @see BWAPI::UnitType::isWorker
    DLLEXPORT extern const PtrUnitFilter IsWorker;

    /// @see BWAPI::UnitType::requiresPsi
    DLLEXPORT extern const PtrUnitFilter RequiresPsi;

    /// @see BWAPI::UnitType::requiresCreep
    DLLEXPORT extern const PtrUnitFilter RequiresCreep;

    /// @see BWAPI::UnitType::isBurrowable
    DLLEXPORT extern const PtrUnitFilter IsBurrowable;

    /// @see BWAPI::UnitType::isCloakable
    DLLEXPORT extern const PtrUnitFilter IsCloakable;

    /// @see BWAPI::UnitType::isBuilding
    DLLEXPORT extern const PtrUnitFilter IsBuilding;

    /// @see BWAPI::UnitType::isAddon
    DLLEXPORT extern const PtrUnitFilter IsAddon;

    /// @see BWAPI::UnitType::isFlyingBuilding
    DLLEXPORT extern const PtrUnitFilter IsFlyingBuilding;

    /// @see BWAPI::UnitType::isNeutral
    DLLEXPORT extern const PtrUnitFilter IsNeutral;

    /// @see BWAPI::UnitType::isHero
    DLLEXPORT extern const PtrUnitFilter IsHero;

    /// @see BWAPI::UnitType::isPowerup
    DLLEXPORT extern const PtrUnitFilter IsPowerup;

    /// @see BWAPI::UnitType::isBeacon
    DLLEXPORT extern const PtrUnitFilter IsBeacon;

    /// @see BWAPI::UnitType::isFlagBeacon
    DLLEXPORT extern const PtrUnitFilter IsFlagBeacon;

    /// @see BWAPI::UnitType::isSpecialBuilding
    DLLEXPORT extern const PtrUnitFilter IsSpecialBuilding;

    /// @see BWAPI::UnitType::isSpell
    DLLEXPORT extern const PtrUnitFilter IsSpell;

    /// @see BWAPI::UnitType::producesLarva
    DLLEXPORT extern const PtrUnitFilter ProducesLarva;

    /// @see BWAPI::UnitType::isMineralField
    DLLEXPORT extern const PtrUnitFilter IsMineralField;

    /// @see BWAPI::UnitType::isCritter
    DLLEXPORT extern const PtrUnitFilter IsCritter;

    /// @see BWAPI::UnitType::canBuildAddon
    DLLEXPORT extern const PtrUnitFilter CanBuildAddon;
  
    /// @see BWAPI::UnitInterface::getHitPoints
    DLLEXPORT extern const PtrIntCompareUnitFilter HP;

    /// @see BWAPI::UnitType::maxHitPoints
    DLLEXPORT extern const PtrIntCompareUnitFilter MaxHP;

    /// <summary>A comparison filter that retrieves the unit's HP percentage.</summary> The formula
    /// is HP*100/MaxHP.
    DLLEXPORT extern const PtrIntCompareUnitFilter HP_Percent;
  
    /// @see BWAPI::UnitInterface::getShields
    DLLEXPORT extern const PtrIntCompareUnitFilter Shields;

    /// @see BWAPI::UnitType::maxShields
    DLLEXPORT extern const PtrIntCompareUnitFilter MaxShields;

    /// <summary>A comparison filter that retrieves the unit's shields percentage.</summary> The
    /// formula is Shields*100/MaxShields.
    DLLEXPORT extern const PtrIntCompareUnitFilter Shields_Percent;
  
    /// @see BWAPI::UnitInterface::getEnergy
    DLLEXPORT extern const PtrIntCompareUnitFilter Energy;
    
    /// @see BWAPI::PlayerInterface::maxEnergy
    DLLEXPORT extern const PtrIntCompareUnitFilter MaxEnergy;
    
    /// <summary>A comparison filter that retrieves the unit's energy percentage.</summary> The
    /// formula is Energy*100/MaxEnergy.
    DLLEXPORT extern const PtrIntCompareUnitFilter Energy_Percent;

    /// @see BWAPI::PlayerInterface::armor
    DLLEXPORT extern const PtrIntCompareUnitFilter Armor;

    /// @see BWAPI::UnitType::armorUpgrade
    DLLEXPORT extern const CompareFilter<Unit ,UpgradeType,UpgradeType (*)(Unit )> ArmorUpgrade;

    /// @see BWAPI::UnitType::mineralPrice
    DLLEXPORT extern const PtrIntCompareUnitFilter MineralPrice;

    /// @see BWAPI::UnitType::gasPrice
    DLLEXPORT extern const PtrIntCompareUnitFilter GasPrice;

    /// @see BWAPI::UnitType::buildTime
    DLLEXPORT extern const PtrIntCompareUnitFilter BuildTime;

    /// @see BWAPI::UnitType::supplyRequired
    DLLEXPORT extern const PtrIntCompareUnitFilter SupplyRequired;

    /// @see BWAPI::UnitType::supplyProvided
    DLLEXPORT extern const PtrIntCompareUnitFilter SupplyProvided;

    /// @see BWAPI::UnitType::spaceRequired
    DLLEXPORT extern const PtrIntCompareUnitFilter SpaceRequired;

    /// @see BWAPI::UnitInterface::getSpaceRemaining
    DLLEXPORT extern const PtrIntCompareUnitFilter SpaceRemaining;

    /// @see BWAPI::UnitType::spaceProvided
    DLLEXPORT extern const PtrIntCompareUnitFilter SpaceProvided;

    /// @see BWAPI::UnitType::buildScore
    DLLEXPORT extern const PtrIntCompareUnitFilter BuildScore;

    /// @see BWAPI::UnitType::destroyScore
    DLLEXPORT extern const PtrIntCompareUnitFilter DestroyScore;

    /// @see BWAPI::PlayerInterface::topSpeed
    DLLEXPORT extern const CompareFilter<Unit ,double,double (*)(Unit )> TopSpeed;

    /// @see BWAPI::PlayerInterface::sightRange
    DLLEXPORT extern const PtrIntCompareUnitFilter SightRange;

    /// @see BWAPI::PlayerInterface::weaponDamageCooldown
    DLLEXPORT extern const PtrIntCompareUnitFilter WeaponCooldown;

    /// @see BWAPI::UnitType::size
    DLLEXPORT extern const CompareFilter<Unit ,UnitSizeType,UnitSizeType (*)(Unit )> SizeType;

    /// @see BWAPI::UnitType::groundWeapon
    DLLEXPORT extern const CompareFilter<Unit ,WeaponType,WeaponType (*)(Unit )> GroundWeapon;

    /// @see BWAPI::UnitType::airWeapon
    DLLEXPORT extern const CompareFilter<Unit ,WeaponType,WeaponType (*)(Unit )> AirWeapon;

    /// @see BWAPI::UnitInterface::getType
    DLLEXPORT extern const CompareFilter<Unit ,UnitType,UnitType (*)(Unit )> GetType;

    /// @see BWAPI::UnitType::getRace
    DLLEXPORT extern const CompareFilter<Unit ,Race,Race (*)(Unit )> GetRace;

    /// @see BWAPI::UnitInterface::getPlayer
    DLLEXPORT extern const CompareFilter<Unit ,Player,Player (*)(Unit )> GetPlayer;
  
    /// @see BWAPI::UnitInterface::getResources
    DLLEXPORT extern const PtrIntCompareUnitFilter Resources;

    /// @see BWAPI::UnitInterface::getResourceGroup
    DLLEXPORT extern const PtrIntCompareUnitFilter ResourceGroup;

    /// @see BWAPI::UnitInterface::getAcidSporeCount
    DLLEXPORT extern const PtrIntCompareUnitFilter AcidSporeCount;

    /// @see BWAPI::UnitInterface::getInterceptorCount
    DLLEXPORT extern const PtrIntCompareUnitFilter InterceptorCount;

    /// @see BWAPI::UnitInterface::getScarabCount
    DLLEXPORT extern const PtrIntCompareUnitFilter ScarabCount;

    /// @see BWAPI::UnitInterface::getSpiderMineCount
    DLLEXPORT extern const PtrIntCompareUnitFilter SpiderMineCount;

    /// @see BWAPI::UnitInterface::getGroundWeaponCooldown
    DLLEXPORT extern const PtrIntCompareUnitFilter MaxWeaponCooldown;

    /// @see BWAPI::UnitInterface::getSpellCooldown
    DLLEXPORT extern const PtrIntCompareUnitFilter SpellCooldown;

    /// @see BWAPI::UnitInterface::getDefenseMatrixPoints
    DLLEXPORT extern const PtrIntCompareUnitFilter DefenseMatrixPoints;

    /// @see BWAPI::UnitInterface::getDefenseMatrixTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter DefenseMatrixTime;

    /// @see BWAPI::UnitInterface::getEnsnareTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter EnsnareTime;

    /// @see BWAPI::UnitInterface::getIrradiateTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter IrradiateTime;

    /// @see BWAPI::UnitInterface::getLockdownTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter LockdownTime;

    /// @see BWAPI::UnitInterface::getMaelstromTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter MaelstromTime;

    /// @see BWAPI::UnitInterface::getOrderTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter OrderTime;

    /// @see BWAPI::UnitInterface::getPlagueTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter PlagueTimer;

    /// @see BWAPI::UnitInterface::getRemoveTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter RemoveTime;

    /// @see BWAPI::UnitInterface::getStasisTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter StasisTime;

    /// @see BWAPI::UnitInterface::getStimTimer
    DLLEXPORT extern const PtrIntCompareUnitFilter StimTime;

    /// @see BWAPI::UnitInterface::getBuildType
    DLLEXPORT extern const CompareFilter<Unit ,UnitType,UnitType (*)(Unit )> BuildType;

    /// @see BWAPI::UnitInterface::getRemainingBuildTime
    DLLEXPORT extern const PtrIntCompareUnitFilter RemainingBuildTime;

    /// @see BWAPI::UnitInterface::getRemainingTrainTime
    DLLEXPORT extern const PtrIntCompareUnitFilter RemainingTrainTime;

    /// @see BWAPI::UnitInterface::getTarget
    DLLEXPORT extern const CompareFilter<Unit ,Unit ,Unit (*)(Unit )> Target;

    /// @see BWAPI::UnitInterface::getOrder
    DLLEXPORT extern const CompareFilter<Unit ,Order,Order (*)(Unit )> CurrentOrder;

    /// @see BWAPI::UnitInterface::getSecondaryOrder
    DLLEXPORT extern const CompareFilter<Unit ,Order,Order (*)(Unit )> SecondaryOrder;

    /// @see BWAPI::UnitInterface::getOrderTarget
    DLLEXPORT extern const CompareFilter<Unit ,Unit ,Unit (*)(Unit )> OrderTarget;

    /// @see BWAPI::UnitInterface::getLeft
    DLLEXPORT extern const PtrIntCompareUnitFilter GetLeft;

    /// @see BWAPI::UnitInterface::getTop
    DLLEXPORT extern const PtrIntCompareUnitFilter GetTop;

    /// @see BWAPI::UnitInterface::getRight
    DLLEXPORT extern const PtrIntCompareUnitFilter GetRight;

    /// @see BWAPI::UnitInterface::getBottom
    DLLEXPORT extern const PtrIntCompareUnitFilter GetBottom;

    /// @see BWAPI::UnitInterface::exists
    DLLEXPORT extern const PtrUnitFilter Exists;

    /// @see BWAPI::UnitInterface::isAttacking
    DLLEXPORT extern const PtrUnitFilter IsAttacking;

    /// @see BWAPI::UnitInterface::isBeingConstructed
    DLLEXPORT extern const PtrUnitFilter IsBeingConstructed;

    /// @see BWAPI::UnitInterface::isBeingGathered
    DLLEXPORT extern const PtrUnitFilter IsBeingGathered;

    /// @see BWAPI::UnitInterface::isBeingHealed
    DLLEXPORT extern const PtrUnitFilter IsBeingHealed;

    /// @see BWAPI::UnitInterface::isBlind
    DLLEXPORT extern const PtrUnitFilter IsBlind;

    /// @see BWAPI::UnitInterface::isBraking
    DLLEXPORT extern const PtrUnitFilter IsBraking;

    /// @see BWAPI::UnitInterface::isBurrowed
    DLLEXPORT extern const PtrUnitFilter IsBurrowed;

    /// @see BWAPI::UnitInterface::isCarryingGas
    DLLEXPORT extern const PtrUnitFilter IsCarryingGas;

    /// @see BWAPI::UnitInterface::isCarryingMinerals
    DLLEXPORT extern const PtrUnitFilter IsCarryingMinerals;

    /// <summary>A unary filter that checks if IsCarryingGas or IsCarryingMinerals return true.</summary>
    DLLEXPORT extern const PtrUnitFilter IsCarryingSomething;

    /// @see BWAPI::UnitInterface::isCloaked
    DLLEXPORT extern const PtrUnitFilter IsCloaked;

    /// @see BWAPI::UnitInterface::isCompleted
    DLLEXPORT extern const PtrUnitFilter IsCompleted;

    /// @see BWAPI::UnitInterface::isConstructing
    DLLEXPORT extern const PtrUnitFilter IsConstructing;

    /// @see BWAPI::UnitInterface::isDefenseMatrixed
    DLLEXPORT extern const PtrUnitFilter IsDefenseMatrixed;

    /// @see BWAPI::UnitInterface::isDetected
    DLLEXPORT extern const PtrUnitFilter IsDetected;

    /// @see BWAPI::UnitInterface::isEnsnared
    DLLEXPORT extern const PtrUnitFilter IsEnsnared;

    /// @see BWAPI::UnitInterface::isFollowing
    DLLEXPORT extern const PtrUnitFilter IsFollowing;

    /// @see BWAPI::UnitInterface::isGatheringGas
    DLLEXPORT extern const PtrUnitFilter IsGatheringGas;

    /// @see BWAPI::UnitInterface::isGatheringMinerals
    DLLEXPORT extern const PtrUnitFilter IsGatheringMinerals;

    /// @see BWAPI::UnitInterface::isHallucination
    DLLEXPORT extern const PtrUnitFilter IsHallucination;

    /// @see BWAPI::UnitInterface::isHoldingPosition
    DLLEXPORT extern const PtrUnitFilter IsHoldingPosition;

    /// @see BWAPI::UnitInterface::isIdle
    DLLEXPORT extern const PtrUnitFilter IsIdle;

    /// @see BWAPI::UnitInterface::isInterruptible
    DLLEXPORT extern const PtrUnitFilter IsInterruptible;

    /// @see BWAPI::UnitInterface::isInvincible
    DLLEXPORT extern const PtrUnitFilter IsInvincible;

    /// @see BWAPI::UnitInterface::isIrradiated
    DLLEXPORT extern const PtrUnitFilter IsIrradiated;

    /// @see BWAPI::UnitInterface::isLifted
    DLLEXPORT extern const PtrUnitFilter IsLifted;

    /// @see BWAPI::UnitInterface::isLoaded
    DLLEXPORT extern const PtrUnitFilter IsLoaded;

    /// @see BWAPI::UnitInterface::isLockedDown
    DLLEXPORT extern const PtrUnitFilter IsLockedDown;

    /// @see BWAPI::UnitInterface::isMaelstrommed
    DLLEXPORT extern const PtrUnitFilter IsMaelstrommed;

    /// @see BWAPI::UnitInterface::isMorphing
    DLLEXPORT extern const PtrUnitFilter IsMorphing;

    /// @see BWAPI::UnitInterface::isMoving
    DLLEXPORT extern const PtrUnitFilter IsMoving;

    /// @see BWAPI::UnitInterface::isParasited
    DLLEXPORT extern const PtrUnitFilter IsParasited;

    /// @see BWAPI::UnitInterface::isPatrolling
    DLLEXPORT extern const PtrUnitFilter IsPatrolling;

    /// @see BWAPI::UnitInterface::isPlagued
    DLLEXPORT extern const PtrUnitFilter IsPlagued;

    /// @see BWAPI::UnitInterface::isRepairing
    DLLEXPORT extern const PtrUnitFilter IsRepairing;

    /// @see BWAPI::UnitInterface::isResearching
    DLLEXPORT extern const PtrUnitFilter IsResearching;

    /// @see BWAPI::UnitInterface::isSieged
    DLLEXPORT extern const PtrUnitFilter IsSieged;

    /// @see BWAPI::UnitInterface::isStartingAttack
    DLLEXPORT extern const PtrUnitFilter IsStartingAttack;

    /// @see BWAPI::UnitInterface::isStasised
    DLLEXPORT extern const PtrUnitFilter IsStasised;

    /// @see BWAPI::UnitInterface::isStimmed
    DLLEXPORT extern const PtrUnitFilter IsStimmed;

    /// @see BWAPI::UnitInterface::isStuck
    DLLEXPORT extern const PtrUnitFilter IsStuck;

    /// @see BWAPI::UnitInterface::isTraining
    DLLEXPORT extern const PtrUnitFilter IsTraining;

    /// @see BWAPI::UnitInterface::isUnderAttack
    DLLEXPORT extern const PtrUnitFilter IsUnderAttack;

    /// @see BWAPI::UnitInterface::isUnderDarkSwarm
    DLLEXPORT extern const PtrUnitFilter IsUnderDarkSwarm;

    /// @see BWAPI::UnitInterface::isUnderDisruptionWeb
    DLLEXPORT extern const PtrUnitFilter IsUnderDisruptionWeb;

    /// @see BWAPI::UnitInterface::isUnderStorm
    DLLEXPORT extern const PtrUnitFilter IsUnderStorm;

    /// @see BWAPI::UnitInterface::isPowered
    DLLEXPORT extern const PtrUnitFilter IsPowered;

    /// @see BWAPI::UnitInterface::isVisible
    DLLEXPORT extern const PtrUnitFilter IsVisible;
  
    /// <summary>A unary filter that checks if the current unit is an enemy of the BWAPI player.</summary>
    /// @note This will always be false when the BWAPI Player is unspecified, such as in a replay.
    DLLEXPORT extern const PtrUnitFilter IsEnemy;

    /// <summary>A unary filter that checks if the current unit is an ally of the BWAPI player.</summary>
    /// @note This will always be false when the BWAPI Player is unspecified, such as in a replay.
    DLLEXPORT extern const PtrUnitFilter IsAlly;

    /// <summary>A unary filter that checks if the current unit is owned by the BWAPI player.</summary>
    /// @note This will always be false when the BWAPI Player is unspecified, such as in a replay.
    DLLEXPORT extern const PtrUnitFilter IsOwned;
  }
}

