// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PSGAM_Inv : ModuleRules
{
	public PSGAM_Inv(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PSGAM_Inv",
			"PSGAM_Inv/Variant_Horror",
			"PSGAM_Inv/Variant_Horror/UI",
			"PSGAM_Inv/Variant_Shooter",
			"PSGAM_Inv/Variant_Shooter/AI",
			"PSGAM_Inv/Variant_Shooter/UI",
			"PSGAM_Inv/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
