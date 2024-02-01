// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionRoguelike/Public/SInteractorComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSInteractorComponent() {}
// Cross Module References
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_USInteractorComponent_NoRegister();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_USInteractorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ActionRoguelike();
// End Cross Module References
	DEFINE_FUNCTION(USInteractorComponent::execPrimaryInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PrimaryInteract();
		P_NATIVE_END;
	}
	void USInteractorComponent::StaticRegisterNativesUSInteractorComponent()
	{
		UClass* Class = USInteractorComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PrimaryInteract", &USInteractorComponent::execPrimaryInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SInteractorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USInteractorComponent, nullptr, "PrimaryInteract", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USInteractorComponent_PrimaryInteract()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USInteractorComponent_PrimaryInteract_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USInteractorComponent_NoRegister()
	{
		return USInteractorComponent::StaticClass();
	}
	struct Z_Construct_UClass_USInteractorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USInteractorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ActionRoguelike,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USInteractorComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USInteractorComponent_PrimaryInteract, "PrimaryInteract" }, // 2311687718
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USInteractorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "SInteractorComponent.h" },
		{ "ModuleRelativePath", "Public/SInteractorComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USInteractorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USInteractorComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USInteractorComponent_Statics::ClassParams = {
		&USInteractorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USInteractorComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USInteractorComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USInteractorComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USInteractorComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USInteractorComponent, 3053178411);
	template<> ACTIONROGUELIKE_API UClass* StaticClass<USInteractorComponent>()
	{
		return USInteractorComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USInteractorComponent(Z_Construct_UClass_USInteractorComponent, &USInteractorComponent::StaticClass, TEXT("/Script/ActionRoguelike"), TEXT("USInteractorComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USInteractorComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
