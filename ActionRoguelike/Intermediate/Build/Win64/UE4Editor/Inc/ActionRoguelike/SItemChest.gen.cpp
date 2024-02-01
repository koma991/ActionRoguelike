// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionRoguelike/Public/SItemChest.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSItemChest() {}
// Cross Module References
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_ASItemChest_NoRegister();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_ASItemChest();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ActionRoguelike();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_USGameplayInterface_NoRegister();
// End Cross Module References
	void ASItemChest::StaticRegisterNativesASItemChest()
	{
	}
	UClass* Z_Construct_UClass_ASItemChest_NoRegister()
	{
		return ASItemChest::StaticClass();
	}
	struct Z_Construct_UClass_ASItemChest_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseMeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BaseMeshComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LidMeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LidMeshComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetPitch_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TargetPitch;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASItemChest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ActionRoguelike,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASItemChest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SItemChest.h" },
		{ "ModuleRelativePath", "Public/SItemChest.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASItemChest_Statics::NewProp_BaseMeshComp_MetaData[] = {
		{ "Category", "SItemChest" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SItemChest.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASItemChest_Statics::NewProp_BaseMeshComp = { "BaseMeshComp", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASItemChest, BaseMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASItemChest_Statics::NewProp_BaseMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASItemChest_Statics::NewProp_BaseMeshComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASItemChest_Statics::NewProp_LidMeshComp_MetaData[] = {
		{ "Category", "SItemChest" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SItemChest.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASItemChest_Statics::NewProp_LidMeshComp = { "LidMeshComp", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASItemChest, LidMeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASItemChest_Statics::NewProp_LidMeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASItemChest_Statics::NewProp_LidMeshComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASItemChest_Statics::NewProp_TargetPitch_MetaData[] = {
		{ "Category", "SItemChest" },
		{ "ModuleRelativePath", "Public/SItemChest.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASItemChest_Statics::NewProp_TargetPitch = { "TargetPitch", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASItemChest, TargetPitch), METADATA_PARAMS(Z_Construct_UClass_ASItemChest_Statics::NewProp_TargetPitch_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASItemChest_Statics::NewProp_TargetPitch_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASItemChest_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASItemChest_Statics::NewProp_BaseMeshComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASItemChest_Statics::NewProp_LidMeshComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASItemChest_Statics::NewProp_TargetPitch,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ASItemChest_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_USGameplayInterface_NoRegister, (int32)VTABLE_OFFSET(ASItemChest, ISGameplayInterface), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASItemChest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASItemChest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASItemChest_Statics::ClassParams = {
		&ASItemChest::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASItemChest_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASItemChest_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASItemChest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASItemChest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASItemChest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASItemChest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASItemChest, 4093768302);
	template<> ACTIONROGUELIKE_API UClass* StaticClass<ASItemChest>()
	{
		return ASItemChest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASItemChest(Z_Construct_UClass_ASItemChest, &ASItemChest::StaticClass, TEXT("/Script/ActionRoguelike"), TEXT("ASItemChest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASItemChest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
