// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHALKGAME_PaintComponent_generated_h
#error "PaintComponent.generated.h already included, missing '#pragma once' in PaintComponent.h"
#endif
#define CHALKGAME_PaintComponent_generated_h

#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_SPARSE_DATA
#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPaint);


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPaint);


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPaintComponent(); \
	friend struct Z_Construct_UClass_UPaintComponent_Statics; \
public: \
	DECLARE_CLASS(UPaintComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChalkGame"), NO_API) \
	DECLARE_SERIALIZER(UPaintComponent)


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUPaintComponent(); \
	friend struct Z_Construct_UClass_UPaintComponent_Statics; \
public: \
	DECLARE_CLASS(UPaintComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ChalkGame"), NO_API) \
	DECLARE_SERIALIZER(UPaintComponent)


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPaintComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPaintComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaintComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaintComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPaintComponent(UPaintComponent&&); \
	NO_API UPaintComponent(const UPaintComponent&); \
public:


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPaintComponent(UPaintComponent&&); \
	NO_API UPaintComponent(const UPaintComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPaintComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPaintComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPaintComponent)


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_PRIVATE_PROPERTY_OFFSET
#define ChalkGame_Source_ChalkGame_PaintComponent_h_10_PROLOG
#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_SPARSE_DATA \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_RPC_WRAPPERS \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_INCLASS \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ChalkGame_Source_ChalkGame_PaintComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_SPARSE_DATA \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_INCLASS_NO_PURE_DECLS \
	ChalkGame_Source_ChalkGame_PaintComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHALKGAME_API UClass* StaticClass<class UPaintComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ChalkGame_Source_ChalkGame_PaintComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
