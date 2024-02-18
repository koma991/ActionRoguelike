// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionRoguelike/Public/SLevel.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSLevel() {}
// Cross Module References
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_ASLevel_NoRegister();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_ASLevel();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ActionRoguelike();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_AExplosiveBarrel_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASLevel::execExplode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Explode();
		P_NATIVE_END;
	}
	void ASLevel::StaticRegisterNativesASLevel()
	{
		UClass* Class = ASLevel::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Explode", &ASLevel::execExplode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASLevel_Explode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASLevel_Explode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASLevel_Explode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASLevel, nullptr, "Explode", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASLevel_Explode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASLevel_Explode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASLevel_Explode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASLevel_Explode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASLevel_NoRegister()
	{
		return ASLevel::StaticClass();
	}
	struct Z_Construct_UClass_ASLevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Barrel_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Barrel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HandMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HandMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bHasDown_MetaData[];
#endif
		static void NewProp_bHasDown_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHasDown;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASLevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ActionRoguelike,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASLevel_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASLevel_Explode, "Explode" }, // 922195883
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLevel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SLevel.h" },
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLevel_Statics::NewProp_Barrel_MetaData[] = {
		{ "Category", "SLevel" },
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASLevel_Statics::NewProp_Barrel = { "Barrel", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASLevel, Barrel), Z_Construct_UClass_AExplosiveBarrel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASLevel_Statics::NewProp_Barrel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::NewProp_Barrel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLevel_Statics::NewProp_BaseMesh_MetaData[] = {
		{ "Category", "SLevel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASLevel_Statics::NewProp_BaseMesh = { "BaseMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASLevel, BaseMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASLevel_Statics::NewProp_BaseMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::NewProp_BaseMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLevel_Statics::NewProp_HandMesh_MetaData[] = {
		{ "Category", "SLevel" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASLevel_Statics::NewProp_HandMesh = { "HandMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASLevel, HandMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASLevel_Statics::NewProp_HandMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::NewProp_HandMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown_MetaData[] = {
		{ "Category", "SLevel" },
		{ "ModuleRelativePath", "Public/SLevel.h" },
	};
#endif
	void Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown_SetBit(void* Obj)
	{
		((ASLevel*)Obj)->bHasDown = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown = { "bHasDown", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASLevel), &Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASLevel_Statics::NewProp_Barrel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASLevel_Statics::NewProp_BaseMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASLevel_Statics::NewProp_HandMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASLevel_Statics::NewProp_bHasDown,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASLevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASLevel>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASLevel_Statics::ClassParams = {
		&ASLevel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASLevel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASLevel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASLevel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASLevel()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASLevel_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASLevel, 3205336631);
	template<> ACTIONROGUELIKE_API UClass* StaticClass<ASLevel>()
	{
		return ASLevel::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASLevel(Z_Construct_UClass_ASLevel, &ASLevel::StaticClass, TEXT("/Script/ActionRoguelike"), TEXT("ASLevel"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASLevel);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
