// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectHL2 : ModuleRules
{
	public ProjectHL2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "MotionTrajectory" });
	}
}
