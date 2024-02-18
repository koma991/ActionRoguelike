// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ACTIONROGUELIKE_SCharacter_generated_h
#error "SCharacter.generated.h already included, missing '#pragma once' in SCharacter.h"
#endif
#define ACTIONROGUELIKE_SCharacter_generated_h

#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_SPARSE_DATA
#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_RPC_WRAPPERS
#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASCharacter(); \
	friend struct Z_Construct_UClass_ASCharacter_Statics; \
public: \
	DECLARE_CLASS(ASCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ActionRoguelike"), NO_API) \
	DECLARE_SERIALIZER(ASCharacter)


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesASCharacter(); \
	friend struct Z_Construct_UClass_ASCharacter_Statics; \
public: \
	DECLARE_CLASS(ASCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ActionRoguelike"), NO_API) \
	DECLARE_SERIALIZER(ASCharacter)


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASCharacter(ASCharacter&&); \
	NO_API ASCharacter(const ASCharacter&); \
public:


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASCharacter(ASCharacter&&); \
	NO_API ASCharacter(const ASCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASCharacter)


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileClass() { return STRUCT_OFFSET(ASCharacter, ProjectileClass); } \
	FORCEINLINE static uint32 __PPO__SpringArmComp() { return STRUCT_OFFSET(ASCharacter, SpringArmComp); } \
	FORCEINLINE static uint32 __PPO__CameraComp() { return STRUCT_OFFSET(ASCharacter, CameraComp); } \
	FORCEINLINE static uint32 __PPO__InsteractComp() { return STRUCT_OFFSET(ASCharacter, InsteractComp); } \
	FORCEINLINE static uint32 __PPO__DrawScale() { return STRUCT_OFFSET(ASCharacter, DrawScale); } \
	FORCEINLINE static uint32 __PPO__Thickness() { return STRUCT_OFFSET(ASCharacter, Thickness); } \
	FORCEINLINE static uint32 __PPO__AttackAnim() { return STRUCT_OFFSET(ASCharacter, AttackAnim); } \
	FORCEINLINE static uint32 __PPO__MoveSpeed() { return STRUCT_OFFSET(ASCharacter, MoveSpeed); }


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_17_PROLOG
#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_SPARSE_DATA \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_RPC_WRAPPERS \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_INCLASS \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_SPARSE_DATA \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_INCLASS_NO_PURE_DECLS \
	ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ACTIONROGUELIKE_API UClass* StaticClass<class ASCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ActionRoguelike_Source_ActionRoguelike_Public_SCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
