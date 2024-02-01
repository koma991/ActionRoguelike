// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ActionRoguelike/Public/SGameplayInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSGameplayInterface() {}
// Cross Module References
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_USGameplayInterface_NoRegister();
	ACTIONROGUELIKE_API UClass* Z_Construct_UClass_USGameplayInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_ActionRoguelike();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ISGameplayInterface::execInterface)
	{
		P_GET_OBJECT(APawn,Z_Param_pawn);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interface_Implementation(Z_Param_pawn);
		P_NATIVE_END;
	}
	void ISGameplayInterface::Interface(APawn* pawn)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Interface instead.");
	}
	void USGameplayInterface::StaticRegisterNativesUSGameplayInterface()
	{
		UClass* Class = USGameplayInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interface", &ISGameplayInterface::execInterface },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USGameplayInterface_Interface_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_pawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USGameplayInterface_Interface_Statics::NewProp_pawn = { "pawn", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SGameplayInterface_eventInterface_Parms, pawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USGameplayInterface_Interface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USGameplayInterface_Interface_Statics::NewProp_pawn,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USGameplayInterface_Interface_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SGameplayInterface.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USGameplayInterface_Interface_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USGameplayInterface, nullptr, "Interface", nullptr, nullptr, sizeof(SGameplayInterface_eventInterface_Parms), Z_Construct_UFunction_USGameplayInterface_Interface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USGameplayInterface_Interface_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USGameplayInterface_Interface_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USGameplayInterface_Interface_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USGameplayInterface_Interface()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USGameplayInterface_Interface_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USGameplayInterface_NoRegister()
	{
		return USGameplayInterface::StaticClass();
	}
	struct Z_Construct_UClass_USGameplayInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USGameplayInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_ActionRoguelike,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USGameplayInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USGameplayInterface_Interface, "Interface" }, // 1545894900
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USGameplayInterface_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SGameplayInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USGameplayInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISGameplayInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USGameplayInterface_Statics::ClassParams = {
		&USGameplayInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_USGameplayInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USGameplayInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USGameplayInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USGameplayInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USGameplayInterface, 2368680023);
	template<> ACTIONROGUELIKE_API UClass* StaticClass<USGameplayInterface>()
	{
		return USGameplayInterface::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USGameplayInterface(Z_Construct_UClass_USGameplayInterface, &USGameplayInterface::StaticClass, TEXT("/Script/ActionRoguelike"), TEXT("USGameplayInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USGameplayInterface);
	static FName NAME_USGameplayInterface_Interface = FName(TEXT("Interface"));
	void ISGameplayInterface::Execute_Interface(UObject* O, APawn* pawn)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USGameplayInterface::StaticClass()));
		SGameplayInterface_eventInterface_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USGameplayInterface_Interface);
		if (Func)
		{
			Parms.pawn=pawn;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (ISGameplayInterface*)(O->GetNativeInterfaceAddress(USGameplayInterface::StaticClass())))
		{
			I->Interface_Implementation(pawn);
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
