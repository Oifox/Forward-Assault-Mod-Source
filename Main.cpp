#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include "Includes/obfuscate.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Menu.h"
#include "Toast.h"
#include <And64InlineHook/And64InlineHook.hpp>
#include <chrono>
#include <pthread.h>
#include <jni.h>
#include <dlfcn.h>
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include <pthread.h>
#include <jni.h>
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include <sstream>
#include <codecvt>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "Unity/Chams.h"
#include "HOOK.h"
#include "Unity/Rect.h"
#include "Unity/Vector3.h"
#include "Unity/Unity.h"
#include "Unity/Quaternion.h"

#if defined(__aarch64__)
//#include <And64InlineHook/And64InlineHook.hpp>
#else

#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>

#endif


// fancy struct for patches for kittyMemory
struct My_Patches {
     MemoryPatch procodeleecher,bouzeleecher,voidclown;
} hexPatches;
bool ESP, ESPTeamminate, ESPLine, ESPBox, ESPHealth, ESPCrosshair, ESPCircle, underground, wchams, hudtext, kills, telekill, masskill, fireshoot, scale = false;
bool ESPRGB = false;
Color color; /*Цвет есп*/
int ESPBoxStyle = 1; /*Настройка коробки*/
int ESPLineLocation = 2.4; /*Расположение линий*/
bool TEST = false;
bool TEST2 = false;
int rq = 1;
int gq = 0;
int bq = 1;
int def = 0;
int deff = 0;
int re = 255;
int ge = 0;
int be =0;

int ae = 0;
int me = 0;
int setid = 0;
int GLOVES = 0;
bool chamstoggle = false;
bool chamstoggle2 = false;
bool OK = false;
bool AIMBOT = false;
bool AUTO = false;
bool AIMV2 = false;
float upval;
float upval2;
float upval3;
float aimdist = 1.0f;
float aimangles = 1.0f;
bool usedist = false;
bool useangle = false;
bool head = false;

#define targetLibName OBFUSCATE("libil2cpp.so")

extern "C" {
JNIEXPORT jobjectArray
JNICALL
Java_com_simplefucker_source_ModMenu_getSettings(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("0_Category_First Color"),
            OBFUSCATE("-110_InputValue_First Color Red"),
            OBFUSCATE("-112_InputValue_First Color Green"),
            OBFUSCATE("-111_InputValue_First Color Blue"),
            OBFUSCATE("0_Category_Secondary Color"),
            OBFUSCATE("-210_InputValue_First Color Red"),
            OBFUSCATE("-212_InputValue_First Color Green"),
            OBFUSCATE("-211_InputValue_First Color Blue"),
    };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}












//////Visuals menu
JNIEXPORT jobjectArray
JNICALL
Java_com_simplefucker_source_ModMenu_getPlayer(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("0_Category_Visuals Menu"),
            OBFUSCATE("1_Toggle_Defaut Chams"),//1
            OBFUSCATE("2_Toggle_RGB Chams"),//2
			OBFUSCATE("3_Toggle_Chams Wallhack"),//3
			OBFUSCATE("4_SeekBar_Color R_0_255"),//4
            OBFUSCATE("5_SeekBar_Color G_0_255"),//5
            OBFUSCATE("6_SeekBar_Color B_0_255"),//6
			
			
			};

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}






//////ESP MENU
JNIEXPORT jobjectArray
JNICALL
Java_com_simplefucker_source_ModMenu_getVisuals(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("Category_Esp Menu"),
            OBFUSCATE("7_Toggle_Esp"),//7
            OBFUSCATE("8_Toggle_Esp Line"),//8
            OBFUSCATE("9_Toggle_Esp Box"),//9
		    OBFUSCATE("10_Toggle_Esp Health"),//10
            OBFUSCATE("11_Toggle_ESP RGB"),//11
            
			OBFUSCATE("0_Category_Esp Setimgs"),
			OBFUSCATE("300_SeekBar_Esp Color_0_7"),//6
            OBFUSCATE("301_SeekBar_Esp Hight_0_100"),//7
            OBFUSCATE("302_SeekBar_Esp Box Size_0_100"),//8
			OBFUSCATE("303_SeekBar_Esp Box Width_0_100"),//9
  };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

//(Feature number)_Category_(text)
// (Feature number)_Toggle_(feature name)
// (Feature number)_SeekBar_(feature name)_(min value)_(max value)
// (Feature number)_Spinner_(feature name)_(Items e.g. item1,item2,item3)
// (Feature number)_Button_(feature name)
// (Feature number)_ButtonLink_(feature name)_(URL/Link here)
// (Feature number)_ButtonOnOff_(feature name)
// (Feature number)_InputValue_(feature name)
// (Feature number)_CheckBox_(feature name)
// (Feature number)_RadioButton_(feature name)_(Items e.g. radio1,radio2,radio3)
// (Feature number)_RichTextView_(Text with limited HTML support)
// (Feature number)_RichWebView_(Full HTML support)

/////Player 
JNIEXPORT jobjectArray
JNICALL
Java_com_simplefucker_source_ModMenu_getMisc(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("0_Category_Player Menu"),
            OBFUSCATE("12_Toggle_Telekill"),//11
            OBFUSCATE("13_Toggle_Masskill"),//12
			
			
			
		    
			OBFUSCATE("16_Toggle_AimBot"),//16
			OBFUSCATE("17_Toggle_Aim HeadShot"),//16
            OBFUSCATE("70_SeekBar_Aim Distance_0_120"),//9
			
			OBFUSCATE("15_Spinner_Set Weapon_OFF,A91, AK47,AWP,  Beretta, BrassKnuckles,ButterflyKnife,  C4,DesertEagle,  CX70, FAL,FiveSeven,Flashbang, FAMAS,  Glock, Huntsman, Karambit, Knife, M1014, M40,M4A1,  M98, MP5K,MP7,  MP9, P250, P90, PP2000, Spas12,Uzi,Tec9  "),//14

           //OBFUSCATE("15_InputValue_Set id weapon 2~35"),//15
			
			};

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}






JNIEXPORT jobjectArray
JNICALL
Java_com_simplefucker_source_ModMenu_getWeapon(JNIEnv *env, jobject activityObject) {
    jobjectArray ret;

    const char *features[] = {
        OBFUSCATE("0_Category_Xd"), //13
			   };

    int Total_Feature = (sizeof features /
                         sizeof features[0]); //Now you dont have to manually update the number everytime;
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));
    int i;
    for (i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    pthread_t ptid;
    pthread_create(&ptid, NULL, antiLeech, NULL);

    return (ret);
}

JNIEXPORT void JNICALL
Java_com_simplefucker_source_SavedPrefs_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                                jint feature, jint value, jboolean boolean, jstring str) {

    const char *featureName = env->GetStringUTFChars(str, 0);

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d"), feature, featureName, value,
         boolean);

    //!!! BE CAREFUL NOT TO ACCIDENTLY REMOVE break; !!!//

    switch (feature) {
        
		case 1:
 chamstoggle = boolean;
            if (chamstoggle) {
                SetRainbow(true);
           MakeToast(env, obj, OBFUSCATE("Chams V1 On"), Toast::LENGTH_SHORT); 
} else {
			   SetRainbow(false);
				MakeToast(env, obj, OBFUSCATE("Chams V1 Off"), Toast::LENGTH_SHORT);
}
         break;
		case 2:
 chamstoggle2 = boolean;
            if (chamstoggle2) {
                SetRainbow1(true);
           MakeToast(env, obj, OBFUSCATE("RGB Chams ON"), Toast::LENGTH_SHORT);
 
} else {
			   SetRainbow1(false);
				MakeToast(env, obj, OBFUSCATE("RGB Chams OFF"), Toast::LENGTH_SHORT);
}
         break;	
		case 3:
TEST2 = boolean;
	if(TEST2){
SetWallhack(true);
SetWallhackW(true);
SetWallhackG(true);
SetWallhackO(true);
MakeToast(env, obj, OBFUSCATE("Chams bypass ON"), Toast::LENGTH_SHORT);
}	else{
MakeToast(env, obj, OBFUSCATE("Chams bypass OFF"), Toast::LENGTH_SHORT);
	}
break;
		 case 4:
            SetR(value);
            break;
        case 5:
            SetG(value);
            break;
        case 6:
            SetB(value);
            break;
		case 7:
            ESP = boolean;
            if(ESP){
          MakeToast(env, obj, OBFUSCATE("Esp On"), Toast::LENGTH_SHORT);
ESPBoxStyle = 1;
       shit = SHIT::White(255);
     }else{
     MakeToast(env, obj, OBFUSCATE("Esp OFF"), Toast::LENGTH_SHORT);	
    }
	   break;
   case 8:
            ESPLine = boolean;
       if(ESPLine){
  MakeToast(env, obj, OBFUSCATE("Esp Line On"), Toast::LENGTH_SHORT);
    }else{
     MakeToast(env, obj, OBFUSCATE("Esp Line OFF"), Toast::LENGTH_SHORT);	
    }
break;
    case 9:
            ESPBox = boolean;
       if(ESPBox){
   MakeToast(env, obj, OBFUSCATE("Esp Box On"), Toast::LENGTH_SHORT);

     }else{
     MakeToast(env, obj, OBFUSCATE("Esp Box OFF"), Toast::LENGTH_SHORT);	
    } 
break;
   case 10:
            ESPHealth = boolean;
          if(ESPHealth){
MakeToast(env, obj, OBFUSCATE("Esp Health On"), Toast::LENGTH_SHORT);
  }else{
     MakeToast(env, obj, OBFUSCATE("Esp Health OFF"), Toast::LENGTH_SHORT);	
     }
break;
case 11:
			ESPRGB = boolean;
			if(ESPRGB){
MakeToast(env, obj, OBFUSCATE("Esp RGB On"), Toast::LENGTH_SHORT);
			     }else{
     MakeToast(env, obj, OBFUSCATE("Esp RGB OFF"), Toast::LENGTH_SHORT);	
    
}
break;
case 300:
            switch (value) {
                case 0:
                    shit = SHIT::Red(255);
                    break;
                case 1:
                    shit = SHIT::Green(255);
                    break;
                case 2:
                    shit = SHIT::Cyan(255);
                    break; 
                case 3:
                    shit = SHIT::Black(255);
                    break;
                case 4:
                    shit = SHIT::White(255);
                    break;
                case 5:
                    shit = SHIT::Blue(255);
                    break; 
                case 6:
                    shit = SHIT::Yellow(255);
                    break;
                case 7:
                    shit = SHIT::Magenta(255);
                    break;  
            }
            break; 
        case 301:
            upval = (float) value * 0.1;
            break;
        case 302:
            upval2 = (float) value * 0.1;
            break;
        case 303:
            upval3 = (float) value * 0.1;
            break;
case 12:
				telekill = boolean;
				if(telekill){
MakeToast(env, obj, OBFUSCATE("Telekill On"), Toast::LENGTH_SHORT);
			     }else{
     MakeToast(env, obj, OBFUSCATE("Telekill OFF"), Toast::LENGTH_SHORT);	
    
	}
break;
				case 13:
				masskill = boolean;
				if(masskill){
MakeToast(env, obj, OBFUSCATE("Masskill On"), Toast::LENGTH_SHORT);
     }else{
     MakeToast(env, obj, OBFUSCATE("Masskill OFF"), Toast::LENGTH_SHORT);	
    }
 break; 
		 case 15:
					setid = value;
		       MakeToast(env, obj, OBFUSCATE("Set ON"), Toast::LENGTH_SHORT);
					break;
         case 16:
				AIMBOT = boolean;
				if(AIMBOT){
                 MakeToast(env, obj, OBFUSCATE("AimBot On"), Toast::LENGTH_SHORT);
			     }else{
                MakeToast(env, obj, OBFUSCATE("AimBot OFF"), Toast::LENGTH_SHORT);	  
	       }
           break;
		    case 70:
            if (value > 0) {
                usedist = true;
               AUTO = true;
				aimdist = value;
            } else {
                usedist = false;
            AUTO = false;
				}
            break;        
             case 71:
            if (value > 0) {
                useangle = true;
                aimangles = value;
            } else {
                useangle = false;
            }
            break;
		case 17:
		head = boolean;
		if(head){
			MakeToast(env, obj, OBFUSCATE("Aim HeadShot On"), Toast::LENGTH_SHORT);
			}else{
		MakeToast(env, obj, OBFUSCATE("Aim HeadShot OFF"), Toast::LENGTH_SHORT);
		}
		break;
		}
    }
}

//private extern void get_position_Injected(out Vector3 ret);
//Transform.get_position_Injected();
Vector3 get_position(void *transform) {
    if (!transform)
        return Vector3();

    Vector3 position;

    static const auto get_position_injected = reinterpret_cast<uint64_t(__fastcall *)(void *,
                                                                                      Vector3 &)>(getAbsoluteAddress(
            targetLibName, 0x108D1C8));
    get_position_injected(transform, position);

    return position;
}

//Transform.set_position_Injected();
void set_position(void* transform, Vector3 test) {

    if (transform) {
        static const auto set_position_injected = reinterpret_cast<uint64_t(__fastcall*)(void*, Vector3)>(getAbsoluteAddress("libil2cpp.so", 0x108D27C));//set_position_injected //Ttansform
        set_position_injected(transform, test);
    }
}

//Component.get_transform();
void *get_transform(void *player) {
    if (!player)
        return NULL;

    static const auto get_transform_injected = reinterpret_cast<uint64_t(__fastcall *)(
            void *)>(getAbsoluteAddress(targetLibName, 0x136B7F0));//So2 0.15.3 - 0x1420660

    return (void *) get_transform_injected(player);
}

//CameraManager.get_MainCamera();
void *get_camera() {

    static const auto get_camera_injected = reinterpret_cast<uint64_t(__fastcall *)()>(getAbsoluteAddress(
            targetLibName, 0xC0667C));//So2 0.15.3 - 0xBE7234

    return (void *) get_camera_injected();
}

//Screen.get_height();
int get_screen_height() {

    static const auto get_height_injected = reinterpret_cast<uint64_t(__fastcall *)()>(getAbsoluteAddress(
            targetLibName, 0x108208C));//So2 0.15.3 - 0x1A568C8

    return (int) get_height_injected();
}

//Screen.get_width();
int get_screen_width() {

    static const auto get_width_injected = reinterpret_cast<uint64_t(__fastcall *)()>(getAbsoluteAddress(
            targetLibName, 0x1082048));//So2 0.15.3 - 0x1A56880

    return (int) get_width_injected();
}

//Camera.WorldToScreenPoint_Injected
//public Vector3 WorldToScreenPoint(Vector3 position, MonoorSetreo..., out Vector3)

Vector3 WorldToScreenPoint(void *transform, Vector3 test) {
    if (!transform)
        return Vector3();

    Vector3 position;

    static const auto WorldToScreenPoint_Injected = reinterpret_cast<uint64_t(__fastcall *)(void *,
                                                                                            Vector3,
                                                                                            int,
                                                                                            Vector3 &)>(getAbsoluteAddress(
            targetLibName, 0x1368E2C));//So2 0.15.3 - 0x141D0C0
    WorldToScreenPoint_Injected(transform, test, 2, position);

    return position;
}
float GetPlayerHealth(void *player) {
    return *(float *) ((uint64_t) player + 0x16C);
}

bool PlayerAlive(void *player) {
    return player != NULL && GetPlayerHealth(player) > 0;
}

int GetPlayerTeam(void *player) {
    return *(int *) ((uint64_t) player + 0x184);//Standoff 2 0.15.3 - 0x14
}

bool IsPlayerDead(void *player) {
    return player == NULL && GetPlayerHealth(player) < 1;
}

Vector3 GetPlayerLocation(void *player) {
    Vector3 location;
    location = get_position(get_transform(player));

    return location;
}

void *myPlayer = NULL;

struct enemy_t {
    void *object;
    Vector3 location;
    int health;
};

/**Entity_Manager**/
class ESPManager {
public:
    std::vector<enemy_t *> *enemies;

    ESPManager() {
        enemies = new std::vector<enemy_t *>();
    }

    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<enemy_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }

        return false;
    }

    void removeEnemy(enemy_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

    void tryAddEnemy(void *enemyObject) {
        if (isEnemyPresent(enemyObject)) {
            return;
        }

        if (IsPlayerDead(enemyObject)) {
            return;
        }

        enemy_t *newEnemy = new enemy_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }

    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            enemy_t *current = (*enemies)[i];

            if (IsPlayerDead(current->object)) {
                enemies->erase(enemies->begin() + i);
            }

            if ((GetPlayerTeam(myPlayer) == GetPlayerTeam(current->object))) {
                enemies->erase(enemies->begin() + i);
            }
        }
    }

    void removeEnemyGivenObject(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i]->object == enemyObject) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

};

ESPManager *espManager;

SHIT GetPlayerSHIT(void *Player) {
    int MyTeam = GetPlayerTeam(myPlayer);
    int TeamNum = GetPlayerTeam(Player);
    SHIT shit;

    if (MyTeam != TeamNum) {
        shit = SHIT(235, 50, 0, 100);
    } else {
        shit = SHIT(15, 110, 220, 100);
    }


    return shit;
}



extern "C"
JNIEXPORT void JNICALL
Java_com_simplefucker_source_ModMenu_DrawOn(JNIEnv *env, jclass clazz, jobject esp, jobject canvas) {
    jclass Esp = env->GetObjectClass(esp);

    jmethodID DrawFilledRects = env->GetMethodID(Esp, "DrawFilledRect",
                                                 "(Landroid/graphics/Canvas;IIIIFFFF)V");
    jmethodID DrawRect = env->GetMethodID(Esp, "DrawRect",
                                          "(Landroid/graphics/Canvas;IIIIIFFFF)V");
    jmethodID DrawLines = env->GetMethodID(Esp, "DrawLine",
                                           "(Landroid/graphics/Canvas;IIIIFFFFF)V");
    jmethodID DrawText = env->GetMethodID(Esp, "DrawText",
                                          "(Landroid/graphics/Canvas;IIIILjava/lang/String;FFF)V");

    if (ESP) {
        if (espManager->enemies->empty()) {
            return;
        }
        for (int i = 0; i < espManager->enemies->size(); i++) {

            void *Player = (*espManager->enemies)[i]->object;

            if (PlayerAlive(Player) &&
                (GetPlayerTeam(myPlayer) != GetPlayerTeam(Player) || ESPTeamminate)) {
                SHIT clr;
                clr.a = 255;
                Rect rect;
                Vector3 PlayerPos = GetPlayerLocation(Player);
                void *Cam = get_camera();
                Vector3 PosNew = {0.f, 0.f, 0.f};
                PosNew = WorldToScreenPoint(Cam, PlayerPos);
                if (PosNew.z < 1.f) continue;
                Vector3 Origin;
                Origin = PlayerPos;
                Origin.y += 0.7f;
                float posnum = upval; /******* Hight slider * 0.1 ********/
                float posnum2 = upval2;/******* Size slider * 0.1 ********/
				float posnum3 = upval3;
                Origin.y += posnum;
                Vector3 BoxPosNew = {0.f, 0.f, 0.f};
                BoxPosNew = WorldToScreenPoint(Cam, Origin);
                float Hight =
                        abs(BoxPosNew.y - PosNew.y) * (posnum2 / posnum), Width =
                        Hight * 0.60f;

                rect = Rect(BoxPosNew.x - Width / 2.f,
                            get_screen_height() - BoxPosNew.y,
                            Width, Hight
                );
                if (ESPBox) {
                    if (ESPBoxStyle == 0) {
                        env->CallVoidMethod(esp, DrawFilledRects, canvas, (jint) shit.a,
                                            (jint) shit.r, (jint) shit.g, (jint) shit.b,
                                            (jfloat) rect.x, (jfloat) rect.y, 

(jfloat) rect.w,
                                            (jfloat) rect.h);
                                            
                    } else if (ESPBoxStyle == 1) {
                        
 
   env->CallVoidMethod(esp, DrawRect, canvas, (jint) shit.a, (jint) shit.r,
                                            (jint) shit.g, (jint) shit.b, (jint) upval3,//1.5
                                            (jfloat) rect.x, (jfloat) rect.y, (jfloat) rect.w,
                                            (jfloat) rect.h);
 
  

       } else if (ESPBoxStyle == 2) {
                        env->CallVoidMethod(esp, DrawFilledRects, canvas, (jint) clr.a,
                                            (jint) shit.r,
 (jint) shit.g, 
(jint) shit.b,
                                            (jfloat) rect.x, 

(jfloat) rect.y,
 (jfloat) rect.w,
    (jfloat) rect.h);
                        env->CallVoidMethod(esp, DrawRect, canvas, (jint) shit.a, (jint) shit.r,
                                            (jint) shit.g, (jint) shit.b, (jint) upval3,//1.5
                                            (jfloat) rect.x, (jfloat) rect.y, (jfloat) rect.w,
                                            (jfloat) rect.h);
                    }
                }

                if (ESPLine) {
                    env->CallVoidMethod(esp, DrawLines, canvas, (jint) shit.a, (jint) shit.r,
                                        (jint) shit.g, (jint) shit.b, (jfloat) upval3,//1.5
                                        (jfloat) get_screen_width() / ESPLineLocation,
                                        (jfloat) get_screen_height() / 1000,
                                        (jfloat) rect.x + rect.w / 2,
                                        (jfloat) rect.y + rect.h / 20);
                
										
										
							
						
							}
				
             
		
				
				if (ESPHealth) {
           if (GetPlayerHealth(Player) >= 100) {        
  jstring D = env->NewStringUTF("100-HP");
                          env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                        (jint) 0, (jint) 255, (jint) 0,          
     
										
										
										
										D,
                                            (jfloat) rect.x, (jfloat) rect.y -10, (jfloat) 12);
          



          } else {

if (GetPlayerHealth(Player) >= 95) {        
                        jstring F = env->NewStringUTF("95-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 255, (jint) 0,
                                            F,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
                  
                      ///void DrawVerticalHealth(Vector2 end, 


   
	
         } else {

if (GetPlayerHealth(Player) >= 85) {        
                        jstring AF = env->NewStringUTF("85-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 255, (jint) 0,
                                            AF,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);                                 
           
                       
   } else {
   
   if (GetPlayerHealth(Player) >= 80) {        
                        jstring Z = env->NewStringUTF("80-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 255, (jint) 0,
                                            Z,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

   
} else {

if (GetPlayerHealth(Player) >= 75) {        
                        jstring X = env->NewStringUTF("75-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 255, (jint) 0,
                                            X,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

    
} else {

if (GetPlayerHealth(Player) >= 70) {        
                        jstring C = env->NewStringUTF("70-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            C,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

           
} else {

if (GetPlayerHealth(Player) >= 65) {        
                        jstring V = env->NewStringUTF("65-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            V,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
} else {

if (GetPlayerHealth(Player) >= 60) {        
                        jstring B = env->NewStringUTF("60-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            B,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
} else {

if (GetPlayerHealth(Player) >= 55) {        
                        jstring N = env->NewStringUTF("55-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            N,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

} else {

if (GetPlayerHealth(Player) >= 50) {        
                        jstring FY = env->NewStringUTF("50-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            FY,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
} else {

if (GetPlayerHealth(Player) >= 45) {        
                        jstring M = env->NewStringUTF("45-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 0, (jint) 0, (jint) 255,
                                            M,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

} else {

if (GetPlayerHealth(Player) >= 40) {        
                        jstring L = env->NewStringUTF("40-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            L,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
         
} else {

if (GetPlayerHealth(Player) >= 35) {        
                        jstring K = env->NewStringUTF("35-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            K,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
     
} else {

if (GetPlayerHealth(Player) >= 30) {        
                        jstring J = env->NewStringUTF("30-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            J,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);


} else {

if (GetPlayerHealth(Player) >= 25) {        
                        jstring H = env->NewStringUTF("25-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            H,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

} else {

if (GetPlayerHealth(Player) >= 20) {        
                        jstring YT = env->NewStringUTF("20-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            YT,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);


} else {

if (GetPlayerHealth(Player) >= 15) {        
                        jstring U = env->NewStringUTF("15-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            U,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

} else {

if (GetPlayerHealth(Player) >= 10) {        
                        jstring II = env->NewStringUTF("10-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            II,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);

} else {

if (GetPlayerHealth(Player) >= 5) {        
                        jstring PO = env->NewStringUTF("5-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint) 255, (jint) 0, (jint) 0,
                                            PO,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);
          } else {

if (GetPlayerHealth(Player) >= 2) {        
                        jstring PAO = env->NewStringUTF("2-HP");
                        
                        env->CallVoidMethod(esp, DrawText, canvas, (jint) clr.a,
                                            (jint)255, (jint) 0, (jint) 0,
                                            PAO,
                                            (jfloat) rect.x, (jfloat) rect.y - 10, (jfloat) 12);                     

break;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} 
 }     
}	 
 }           

 
            ///   espManager->removeEnemyGivenObject(Player);
  
  
        







void *enemyPlayer = NULL;
Quaternion lookRotation;
void *updatePlayer = NULL;
void (*Player_update)(void *player);
void _Player_update(void *player) {
    if (player != NULL) {
        Player_update(player);

        bool isMine = *(bool *) ((uint64_t) player + 0x84);//Standoff 2 0.15.3 - 0x2C
        updatePlayer = player;

        if (isMine) {
            myPlayer = player;
        }

    if(myPlayer) {
        if(GetPlayerTeam(myPlayer) != GetPlayerTeam(player)) {
        
 
 enemyPlayer = player;
        }
    }
  
 if(enemyPlayer) {
        // checking if it's not dead, if it is enemyPlayer is NULL & it should look for a new one.
     if(!IsPlayerDead(enemyPlayer)) {
           if (AIMBOT) {
float distance = Vector3::Distance(GetPlayerLocation(myPlayer), GetPlayerLocation(enemyPlayer));
if (usedist) {
                        if (distance < aimdist) {
lookRotation = Quaternion::LookRotation((GetPlayerLocation(enemyPlayer) + Vector3(0, -0.65f, 0)) - GetPlayerLocation(myPlayer), Vector3(0, 1, 0));

}else if (head){
	lookRotation = Quaternion::LookRotation((GetPlayerLocation(enemyPlayer) + Vector3(0, -0.50f, 0)) - GetPlayerLocation(myPlayer), Vector3(0, 1, 0));

//} else if (useangle) {
//Vector3 target = GetPlayerLocation(enemyPlayer) - GetPlayerLocation(myPlayer);
                 //////float aimAngle = Vector3::Angle(target, get_forward(get_transform(get_main())) * 100.0f);
                    ///if (aimAngle < aimangles) {
  /// lookRotation = Quaternion::LookRotation((GetPlayerLocation(enemyPlayer) + Vector3(0, -0.65f, 0)) - GetPlayerLocation(myPlayer), Vector3(0, 1, 0)); 

 }
			


   } else {
            enemyPlayer = NULL;
   return;
}     
}
}
} 

  ///}
 ///}
  Player_update(player);


   

 // Checking if enemyPlayer object is not null
      if (enemyPlayer) {

        if (masskill) {
            Vector3 PlayerLocation = GetPlayerLocation(myPlayer);

            set_position(get_transform(enemyPlayer),
                         Vector3(PlayerLocation.x, PlayerLocation.y,
                                 PlayerLocation.z + 1));


}
    
    } else {
        
		
		
		enemyPlayer = NULL;
        return;
    }

	
	
	if (enemyPlayer) {
  

        if (telekill) {
            Vector3 enemyLocation = GetPlayerLocation(enemyPlayer);

            set_position(get_transform(myPlayer),
                         Vector3(enemyLocation.x, enemyLocation.y,
                                 enemyLocation.z - 1));
        }
    }
    Player_update(player);

	
	
	
	if (enemyPlayer) {
if(TEST2){
Vector3 PlayerLocation = GetPlayerLocation(myPlayer);
         ThrowGrenade(get_transform(myPlayer), 91,
                    Vector3(PlayerLocation.x, PlayerLocation.y,
                        PlayerLocation.z), 
                    Vector3(PlayerLocation.x, PlayerLocation.y,
                        PlayerLocation.z), 0, 0);
	}
	}
	Player_update(player);
	
	
	if(ESPRGB){
            if (re == 255){
                if (be == 0 ){
                    if (ge == 255){}
                    else{
                        ge = ge+1;
                    }
                }
            }
            if (ge == 255){
            if (re == 0){} else{
                re = re-1;
            }
        }
        if (ge == 255) {
            if (re == 0) {
                if (be==255){} else{
                    be = be+1;
            }
        }
    }
    if (be == 255) {
        if (ge == 0) {
            me = 1;
            re = re+1;
        }
        else{
            ge = ge-1;
    }
}
if (me == 1){
if (re == 255){
if (be == 0){} else{
be = be-1;
}
}
}
shit = SHIT(re, ge, be, 255);
}

        if (ESP) {
            if (!isMine) {
                if (myPlayer) {
                    if ((GetPlayerTeam(myPlayer) != GetPlayerTeam(player) || ESPTeamminate)) {
                        espManager->tryAddEnemy(player);
                    }
                    espManager->updateEnemies(player);
                }
            }
        }
    }

}
	

		






void (*Player_ondestroy)(void *player);
void _Player_ondestroy(void *player) {
    if (player != NULL) {
        Player_ondestroy(player);
        espManager->removeEnemyGivenObject(player);
    }
}


void (*SendChat)(void* _this, int);
void(*old_MultiPlayerChat_Update)(void *instance);

void MultiPlayerChat_Update(void *instance) {
    if (instance != NULL ) {
        if(setid == 0){

            ///SendChat(instance, );
            
              } else if (setid == 1) {
             SendChat(instance, 16);
           
              } else if (setid == 2) {
             SendChat(instance, 1);
           
              } else if (setid == 3) {
             SendChat(instance, 32);
             
                 } else if (setid == 4) {
             SendChat(instance, 34);
             
                 } else if (setid == 5) {
             SendChat(instance, 35);
             
                 } else if (setid == 6) {
             SendChat(instance, 22);
             
                 } else if (setid == 7) {
             SendChat(instance, 11);
             
                 } else if (setid == 8) {
             SendChat(instance, 3);
             
                 } else if (setid == 9) {
             SendChat(instance, 15);
             
                 } else if (setid == 10) {
             SendChat(instance, 28);
             
                 } else if (setid == 11) {
             SendChat(instance, 8);
             
                 } else if (setid == 12) {
             SendChat(instance, 18);
             
                 } else if (setid == 13) {
             SendChat(instance, 4);
             
                 } else if (setid == 14) {
             SendChat(instance, 26);
             
                 } else if (setid == 15) {
             SendChat(instance, 33);
             
                 } else if (setid == 16) {
             SendChat(instance, 21);
             
                 } else if (setid == 17) {
             SendChat(instance, 14);
             
                 } else if (setid == 18) {
             SendChat(instance, 24);
             
                 } else if (setid == 19) {
             SendChat(instance, 6);
             
                 } else if (setid == 20) {
             SendChat(instance, 5);
             
                 } else if (setid == 21) {
             SendChat(instance, 13);
             
                   } else if (setid == 22) {
             SendChat(instance, 20);
             
                   } else if (setid == 23) {
             SendChat(instance, 10);
             
                   } else if (setid == 24) {
             SendChat(instance, 30);
             
                   } else if (setid == 25) {
             SendChat(instance, 12);
             
                   } else if (setid == 26) {
             SendChat(instance, 31);
             
                   } else if (setid == 27) {
             SendChat(instance, 19);
             
                   } else if (setid == 28) {
             SendChat(instance, 9);
             
                   } else if (setid == 29) {
             SendChat(instance, 27);
             
                   } else if (setid == 30) {
             SendChat(instance, 23);
             
             
 } 
        old_MultiPlayerChat_Update(instance);
    }
    old_MultiPlayerChat_Update(instance);
}

void(*old_FirstPersonLook_Update)(void *gameLooking);
void FirstPersonLook_Update(void *gameLooking) { 
   /// if (AUTO && GetPlayerHealth(enemyPlayer) > 0) {
        if (AUTO) {
         *(Quaternion *) ((uint64_t) gameLooking + 0x2C) = lookRotation;///2C
        }
    
    old_FirstPersonLook_Update(gameLooking);
}   

void(*old_FirstPersonLook_Updateq)(void *gameLooking);
void FirstPersonLook_Updateq(void *gameLooking) { 
   /// if (AUTO && GetPlayerHealth(enemyPlayer) > 0) {
        if (head) {
         *(Quaternion *) ((uint64_t) gameLooking + 0x2C) = lookRotation;///2C
        }
    
    old_FirstPersonLook_Updateq(gameLooking);
}  

void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
        do {
               sleep(1);
    } while (!isLibraryLoaded(targetLibName) && mlovinit());
    
setShader("_BumpMap");
    LogShaders();
    Wallhack();
	
	espManager = new ESPManager();
	
#if defined(__aarch64__) //Compile for arm64 lib only
    
#else //Compile for armv7 lib only. Do not worry about greyed out highlighting code, it still works


MSHookFunction((void *) getAbsoluteAddress(targetLibName, 0x771EB8), (void *) &_Player_update,
                   (void **) &Player_update); //Player.Update(); Standoff 2 0.15.3 - 0x12B0A44
    MSHookFunction((void *) getAbsoluteAddress(targetLibName, 0x767568), (void *) &_Player_ondestroy,
                   (void **) &Player_ondestroy); //Player.OnDestroy();
				   
   

/////set weapons
MSHookFunction((void *) getAbsoluteAddress(targetLibName, 0x6A7A28), (void *) MultiPlayerChat_Update,
                   (void **) &old_MultiPlayerChat_Update);//
            
    SendChat = (void(*)(void *, int))getAbsoluteAddress(targetLibName, 0x68A7AC);//

			
		
		
		MSHookFunction((void *) getAbsoluteAddress("libil2cpp.so", 0x19E2070), (void *) FirstPersonLook_Update,
                   (void **) &old_FirstPersonLook_Update);	
			

               MSHookFunction((void *) getAbsoluteAddress("libil2cpp.so", 0x19E2070), (void *) FirstPersonLook_Updateq,
                   (void **) &old_FirstPersonLook_Updateq);	
		
				   
				   
ThrowGrenade = (void (*)(void*, int, Vector3, Vector3, NEENMHFAOLH))getAbsoluteAddress(targetLibName, 0x686F74);

    SendChat = (void (*)(void*, NEENMHFAOLH)) getAbsoluteAddress(targetLibName, 0x68A7AC);
				   
				   
			
LOGI("SendChat weapon%s", SendChat);
#endif

    return NULL;
}

//JNI calls


//No need to use JNI_OnLoad, since we don't use JNIEnv
//We do this to hide OnLoad from disassembler
__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

/*
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);
    return JNI_VERSION_1_6;
}
 */
 





