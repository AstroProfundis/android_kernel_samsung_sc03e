ui_print("");
ui_print("");
ui_print("------------------------------------------------");
ui_print("@VERSION");
ui_print("Linux kernel for Samsung SC03E, by:");
ui_print("    AstroProfundis");
ui_print("Credits to KBC Developers:");
ui_print("    HomuHomu");
ui_print("    Ma34s");
ui_print("    Sakuramilk");
ui_print("And:");
ui_print("    psndna88");
ui_print("    AndreiLux");
ui_print("------------------------------------------------");
ui_print("");
show_progress(0.500000, 0);

ui_print("Flashing recovery image...");
package_extract_file("recovery.img", "/dev/block/platform/dw_mmc/by-name/RECOVERY");
show_progress(0.100000, 0);

ui_print("Flash complete. Enjoy!");
set_progress(1.000000);

