class EGVAR(context_menu,actions) {
    class FireArtillery {
        displayName = CSTRING(FireArtillery);
        icon = "\a3\ui_f\data\gui\cfg\communicationmenu\artillery_ca.paa";
        insertChildren = QUOTE(_objects call FUNC(getArtilleryActions));
        priority = 70;
    };
    class ThrowGrenade {
        displayName = CSTRING(ThrowGrenade);
        icon = QPATHTOF(ui\grenade_ca.paa);
        insertChildren = QUOTE(_objects call FUNC(getGrenadeActions));
        priority = 70;
    };
    class Behaviour {
        displayName = "$STR_3DEN_Group_Attribute_Behaviour_displayName";
        condition = QUOTE(_groups findIf {units _x findIf {!isPlayer _x} != -1} != -1);
        icon = QPATHTOF(ui\careless_ca.paa);
        priority = 59;
        class Safe {
            displayName = "$STR_safe";
            statement = QUOTE([ARR_2(_groups,_args)] call FUNC(setBehaviour));
            icon = QPATHTOF(ui\safe_ca.paa);
            iconColor[] = {0, 1, 0, 1};
            args = "SAFE";
        };
        class Aware: Safe {
            displayName = "$STR_aware";
            icon = QPATHTOF(ui\aware_ca.paa);
            iconColor[] = {1, 1, 0, 1};
            args = "AWARE";
        };
        class Combat: Safe {
            displayName = "$STR_combat";
            icon = QPATHTOF(ui\combat_ca.paa);
            iconColor[] = {1, 0, 0, 1};
            args = "COMBAT";
        };
        class Stealth: Safe {
            displayName = "$STR_stealth";
            icon = QPATHTOF(ui\stealth_ca.paa);
            iconColor[] = {0, 1, 1, 1};
            args = "STEALTH";
        };
        class Careless: Safe {
            displayName = "$STR_3DEN_Attributes_Behaviour_Careless_text";
            icon = QPATHTOF(ui\careless_ca.paa);
            iconColor[] = {1, 1, 1, 1};
            args = "CARELESS";
        };
    };
    class Stance {
        displayName = "$STR_A3_RscAttributeUnitPos_Title";
        condition = QUOTE(_objects findIf {alive _x && {_x isKindOf 'CAManBase'} && {!isPlayer _x}} != -1);
        icon = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
        priority = 56;
        class Up {
            displayName = "$STR_A3_RscAttributeUnitPos_Up_tooltip";
            statement = QUOTE([ARR_2(_objects,_args)] call FUNC(setStance));
            icon = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
            args = "UP";
        };
        class Middle: Up {
            displayName = "$STR_A3_RscAttributeUnitPos_Crouch_tooltip";
            icon = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_crouch_ca.paa";
            args = "MIDDLE";
        };
        class Down: Up {
            displayName = "$STR_A3_RscAttributeUnitPos_Down_tooltip";
            icon = "\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_prone_ca.paa";
            args = "DOWN";
        };
        class Auto: Up {
            displayName = "$STR_A3_RscAttributeUnitPos_Auto_tooltip";
            icon = QPATHTOF(ui\default_ca.paa);
            args = "AUTO";
        };
    };
    class Loadout {
        displayName = "$STR_A3_VR_Stamina_01_Loadout";
        condition = QUOTE(_hoveredEntity call FUNC(canEditLoadout));
        statement = QUOTE(_hoveredEntity call EFUNC(common,openArsenal));
        icon = "\a3\3den\data\displays\display3den\entitymenu\arsenal_ca.paa";
        priority = 40;
        class Edit {
            displayName = "$STR_3DEN_Display3DEN_MenUBar_Edit_text";
            condition = QUOTE(_hoveredEntity call FUNC(canEditLoadout));
            statement = QUOTE(_hoveredEntity call EFUNC(common,openArsenal));
            icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
        };
        class Copy {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
            statement = QUOTE(GVAR(loadout) = _hoveredEntity call CBA_fnc_getLoadout);
            icon = QPATHTOF(ui\copy_ca.paa);
        };
        class Paste {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
            condition = QUOTE(!isNil QQGVAR(loadout));
            statement = QUOTE([ARR_2(_hoveredEntity,GVAR(loadout))] call CBA_fnc_setLoadout);
            icon = QPATHTOF(ui\paste_ca.paa);
        };
        class Reset {
            displayName = "$STR_A3_RscDisplayCampaignLobby_Reset";
            statement = QUOTE(_hoveredEntity setUnitLoadout configOf _hoveredEntity);
            icon = "\a3\3den\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
        };
        class SwitchWeapon {
            displayName = "$STR_A3_Switch1";
            icon = "\a3\ui_f\data\IGUI\Cfg\Actions\reammo_ca.paa";
            class Primary {
                displayName = "$STR_A3_RSCDisplayArsenal_Tab_PrimaryWeapon";
                condition = QUOTE([ARR_2(_hoveredEntity,_args)] call FUNC(canSwitchWeapon));
                statement = QUOTE([ARR_2(_hoveredEntity,_args)] call FUNC(switchWeapon));
                modifierFunction = QUOTE(call FUNC(switchWeaponModifier));
                icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\primaryWeapon_ca.paa";
                args = 0;
            };
            class Handgun: Primary {
                displayName = "$STR_A3_RSCDisplayArsenal_Tab_Handgun";
                icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\handgun_ca.paa";
                args = 1;
            };
            class Binoculars: Primary {
                displayName = "$STR_A3_RSCDisplayArsenal_Tab_Binoculars";
                icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\binoculars_ca.paa";
                args = 2;
            };
        };
    };
    class Inventory {
        displayName = "$STR_A3_Gear1";
        condition = QUOTE(_hoveredEntity call FUNC(canEditInventory));
        statement = QUOTE(_hoveredEntity call EFUNC(inventory,configure));
        icon = "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_0_ca.paa";
        priority = 39;
        class Edit {
            displayName = "$STR_3DEN_Display3DEN_MenUBar_Edit_text";
            condition = QUOTE(_hoveredEntity call FUNC(canEditInventory));
            statement = QUOTE(_hoveredEntity call EFUNC(inventory,configure));
            icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
        };
        class Copy {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
            statement = QUOTE(GVAR(inventory) = _hoveredEntity call EFUNC(common,serializeInventory));
            icon = QPATHTOF(ui\copy_ca.paa);
        };
        class Paste {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
            condition = QUOTE(!isNil QQGVAR(inventory));
            statement = QUOTE([ARR_2(_hoveredEntity,GVAR(inventory))] call EFUNC(common,deserializeInventory));
            icon = QPATHTOF(ui\paste_ca.paa);
        };
    };
    class VehicleAppearance {
        displayName = CSTRING(VehicleAppearance);
        condition = QUOTE(_hoveredEntity call FUNC(canEditVehicleAppearance));
        statement = QUOTE(_hoveredEntity call EFUNC(garage,openGarage));
        icon = "\a3\3den\data\displays\display3den\entitymenu\garage_ca.paa";
        priority = 38;
        class Edit {
            displayName = "$STR_3DEN_Display3DEN_MenUBar_Edit_text";
            condition = QUOTE(_hoveredEntity call FUNC(canEditVehicleAppearance));
            statement = QUOTE(_hoveredEntity call EFUNC(garage,openGarage));
            icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
        };
        class Copy {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
            statement = QUOTE(_hoveredEntity call FUNC(copyVehicleAppearance));
            icon = QPATHTOF(ui\copy_ca.paa);
        };
        class Paste {
            displayName = "$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
            condition = QUOTE(_hoveredEntity call FUNC(canPasteVehicleAppearance));
            statement = QUOTE(_hoveredEntity call FUNC(pasteVehicleAppearance));
            icon = QPATHTOF(ui\paste_ca.paa);
        };
    };
    class VehicleLogistics {
        displayName = CSTRING(VehicleLogistics);
        icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\truck_ca.paa";
        priority = 37;
        class SwitchWeapon {
            displayName = "$STR_A3_Switch1";
            icon = "\a3\ui_f\data\GUI\Cfg\Hints\VehicleAmmo_CA.paa";
            insertChildren = QUOTE(_hoveredEntity call FUNC(getVehicleWeaponActions));
        };
        class UnloadViV {
            displayName = "$STR_A3_ModuleDepot_Unload";
            condition = QUOTE(_objects call FUNC(canUnloadViV));
            statement = QUOTE(_objects call FUNC(unloadViV));
            icon = "\a3\ui_f\data\IGUI\Cfg\Actions\unloadVehicle_ca.paa";
        };
    };
    class EditableObjects {
        displayName = CSTRING(EditableObjects);
        statement = QUOTE(call FUNC(openEditableObjectsDialog));
        icon = QPATHTOEF(modules,ui\edit_obj_ca.paa);
        priority = 30;
        class Add {
            displayName = ECSTRING(common,Add);
            icon = QPATHTOF(ui\add_ca.paa);
            class 10m {
                displayName = CSTRING(10m);
                statement = QUOTE([ARR_3(true,_position,_args)] call FUNC(updateEditableObjects));
                icon = QPATHTOF(ui\add_ca.paa);
                args = 10;
            };
            class 50m: 10m {
                displayName = CSTRING(50m);
                args = 50;
            };
            class 100m: 10m {
                displayName = CSTRING(100m);
                args = 100;
            };
            class 250m: 10m {
                displayName = CSTRING(250m);
                args = 250;
            };
        };
        class Remove {
            displayName = ECSTRING(common,Remove);
            icon = QPATHTOF(ui\remove_ca.paa);
            class Selected {
                displayName = CSTRING(Selected);
                statement = QUOTE([ARR_3(SELECTED_OBJECTS,false,getAssignedCuratorLogic player)] call EFUNC(common,updateEditableObjects));
                icon = QPATHTOF(ui\remove_ca.paa);
            };
            class 10m: Selected {
                displayName = CSTRING(10m);
                statement = QUOTE([ARR_3(false,_position,_args)] call FUNC(updateEditableObjects));
                args = 10;
            };
            class 50m: 10m {
                displayName = CSTRING(50m);
                args = 50;
            };
            class 100m: 10m {
                displayName = CSTRING(100m);
                args = 100;
            };
            class 250m: 10m {
                displayName = CSTRING(250m);
                args = 250;
            };
        };
    };
    class TeleportZeus {
        displayName = CSTRING(TeleportZeus);
        statement = QUOTE(call FUNC(teleportZeus));
        icon = "\a3\Ui_F_Curator\Data\Logos\arma3_curator_eye_256_ca.paa";
        priority = 10;
    };
};
