class Logic;
class Module_F: Logic
{
	class ArgumentsBaseUnits
	{
		class Units;
	};
	class ModuleDescription
	{
		class AnyBrain;
	};
};
class scriptPresets_ModuleVAS: Module_F
{
	// Standard object definitions
	scope = 2; // Editor visibility; 2 will show it in the menu, 1 will hide it.
	displayName = "Virtual Ammobox System"; // Name displayed in the menu
	icon = "scriptPresets\data\iconScriptPresets_ca.paa"; // Map icon. Delete this entry to use the default icon
	category = "Effects";

	// Name of function triggered once conditions are met
	function = "scriptPresets_fnc_ModuleVAS";
	// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
	functionPriority = 1;
	// 0 for server only execution, 1 for remote execution on all clients upon mission start, 2 for persistent execution
	isGlobal = 1;
	// 1 for module waiting until all synced triggers are activated
	isTriggerActivated = 1;
	// 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
	isDisposable = 1;

	// Menu displayed when the module is placed or double-clicked on by Zeus
	curatorInfoType = "RscDisplayAttributeModuleVAS";

	// Module arguments
	class Arguments: ArgumentsBaseUnits
	{
		// Arguments shared by specific module type (have to be mentioned in order to be placed on top)
		class Units: Units {};
		// Module specific arguments
		class Yield
		{
			displayName = "Nuclear weapon yield"; // Argument label
			description = "How strong will the explosion be"; // Tooltip description
			typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
			class values
			{
				class 50Mt	{name = "50 megatons";	value = 50; default = 1;}; // Listbox item
				class 100Mt	{name = "100 megatons"; value = 100;};
			};
		};
		class Name
		{
			displayName = "Name";
			description = "Name of the nuclear device";
			defaultValue = "Tsar Bomba"; // Default text filled in the input box
			// When no 'values' are defined, input box is displayed instead of listbox
		};
	};

	// Module description. Must inherit from base class, otherwise pre-defined entities won't be available
	class ModuleDescription: ModuleDescription
	{
		description = "Short module description"; // Short description, will be formatted as structured text
		sync[] = {"LocationArea_F"}; // Array of synced entities (can contain base classes)
 
		class LocationArea_F
		{
			description[] = { // Multi-line descriptions are supported
				"First line",
				"Second line"
			};
			position = 1; // Position is taken into effect
			direction = 1; // Direction is taken into effect
			optional = 1; // Synced entity is optional
			duplicate = 1; // Multiple entities of this type can be synced
			synced[] = {"BLUFORunit","AnyBrain"}; // Pre-define entities like "AnyBrain" can be used. See the list below
		};
		class BLUFORunit
		{
			description = "Short description";
			displayName = "Any BLUFOR unit"; // Custom name
			icon = "iconMan"; // Custom icon (can be file path or CfgVehicleIcons entry)
			side = 1; // Custom side (will determine icon color)
		};
	};
};