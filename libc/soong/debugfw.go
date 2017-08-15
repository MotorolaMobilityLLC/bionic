package mtkDebugFW

import (
	"android/soong/android"
	"android/soong/cc"

	"github.com/google/blueprint"
	"github.com/google/blueprint/proptools"
)

func mtkDebugFWDefaults(ctx android.LoadHookContext) {
	type props struct {
		Target struct {
			Android_arm struct {
				Cflags []string
			}
			Android_arm64 struct {
				Cflags []string
			}
		}
	}
	p := &props{}
	featureValue := android.MtkFeatureValues
	if v, found := featureValue["MTK_USER_SPACE_DEBUG_FW"]; found {
		if v == "yes" {
			if proptools.Bool(ctx.AConfig().ProductVariables.Eng) {
				p.Target.Android_arm.Cflags = append(p.Target.Android_arm.Cflags, "-marm")
				p.Target.Android_arm.Cflags = append(p.Target.Android_arm.Cflags, "-fno-omit-frame-pointer")
			}
		}
	}
	ctx.AppendProperties(p)
}

func init() {
	android.RegisterModuleType("mtk_debug_fw_defaults", mtkDebugFWDefaultsFactory)
}

func mtkDebugFWDefaultsFactory() (blueprint.Module, []interface{}) {
	module, props := cc.DefaultsFactory()
	android.AddLoadHook(module, mtkDebugFWDefaults)
	return module, props
}

