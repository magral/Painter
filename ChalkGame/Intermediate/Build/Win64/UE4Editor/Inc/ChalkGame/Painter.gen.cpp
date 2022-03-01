// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ChalkGame/Painter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePainter() {}
// Cross Module References
	CHALKGAME_API UClass* Z_Construct_UClass_APainter_NoRegister();
	CHALKGAME_API UClass* Z_Construct_UClass_APainter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ChalkGame();
// End Cross Module References
	DEFINE_FUNCTION(APainter::execPaint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Paint();
		P_NATIVE_END;
	}
	void APainter::StaticRegisterNativesAPainter()
	{
		UClass* Class = APainter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Paint", &APainter::execPaint },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APainter_Paint_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APainter_Paint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Painter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APainter_Paint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APainter, nullptr, "Paint", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APainter_Paint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APainter_Paint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APainter_Paint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APainter_Paint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APainter_NoRegister()
	{
		return APainter::StaticClass();
	}
	struct Z_Construct_UClass_APainter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APainter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ChalkGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APainter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APainter_Paint, "Paint" }, // 1810910260
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APainter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Painter.h" },
		{ "ModuleRelativePath", "Painter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APainter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APainter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APainter_Statics::ClassParams = {
		&APainter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APainter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APainter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APainter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APainter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APainter, 2515429055);
	template<> CHALKGAME_API UClass* StaticClass<APainter>()
	{
		return APainter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APainter(Z_Construct_UClass_APainter, &APainter::StaticClass, TEXT("/Script/ChalkGame"), TEXT("APainter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APainter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
