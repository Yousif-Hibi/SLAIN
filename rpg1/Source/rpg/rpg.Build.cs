// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class rpg : ModuleRules
{
	public rpg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "GameplayTags",
            "UMG",
            "AIModule",
            "GameplayTasks",
            "NavigationSystem",
            "TextToSpeech",
            "HTTP",
            "Json"

        });


        PrivateDependencyModuleNames.AddRange(new string[] { });

        if (Target.bBuildEditor)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "UnrealEd",
                "EditorScriptingUtilities",
                "StaticMeshEditor"
            });
        }






        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
