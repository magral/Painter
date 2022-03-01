// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChalkGame/PaintComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePaintComponent() {}
// Cross Module References
	CHALKGAME_API UClass* Z_Construct_UClass_UPaintComponent_NoRegister();
	CHALKGAME_API UClass* Z_Construct_UClass_UPaintComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ChalkGame();
// End Cross Module References
	DEFINE_FUNCTION(UPaintComponent::execPaint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Paint();
		P_NATIVE_END;
	}
	void UPaintComponent::StaticRegisterNativesUPaintComponent()
	{
		UClass* Class = UPaintComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Paint", &UPaintComponent::execPaint },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPaintComponent_Paint_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPaintComponent_Paint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "PaintComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPaintComponent_Paint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPaintComponent, nullptr, "Paint", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPaintComponent_Paint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPaintComponent_Paint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPaintComponent_Paint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPaintComponent_Paint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPaintComponent_NoRegister()
	{
		return UPaintComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPaintComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPaintComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ChalkGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPaintComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPaintComponent_Paint, "Paint" }, // 2097517149
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPaintComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PaintComponent.h" },
		{ "ModuleRelativePath", "PaintComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPaintComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPaintComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPaintComponent_Statics::ClassParams = {
		&UPaintComponent::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UPaintComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPaintComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPaintComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPaintComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPaintComponent, 3394490631);
	template<> CHALKGAME_API UClass* StaticClass<UPaintComponent>()
	{
		return UPaintComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPaintComponent(Z_Construct_UClass_UPaintComponent, &UPaintComponent::StaticClass, TEXT("/Script/ChalkGame"), TEXT("UPaintComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPaintComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
