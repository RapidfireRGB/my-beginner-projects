#ifndef POKEMON_NICKNAME_GENERATOR_NAMES_H
#define POKEMON_NICKNAME_GENERATOR_NAMES_H
#include <string>
#include <map>
#include <vector>
#include "gen1_names.h"
#include "gen2_names.h"
#include "gen3_names.h"
#include "gen4_names.h"
#include "gen5_names.h"

// Map of all name strings -> container of nicknames
inline std::map<std::string, std::vector<std::string>> pokedex = {

    // Gen 1
    {"Bulbasaur", bulbasaur_names},
    {"Ivysaur", ivysaur_names},
    {"Venusaur", venusaur_names},

    {"Charmander", charmander_names},
    {"Charmeleon", charmeleon_names},
    {"Charizard", charizard_names},

    {"Squirtle", squirtle_names},
    {"Wartortle", wartortle_names},
    {"Blastoise", blastoise_names},

    {"Caterpie", caterpie_names},
    {"Metapod", metapod_names},
    {"Butterfree", butterfree_names},

    {"Weedle", weedle_names},
    {"Kakuna", kakuna_names},
    {"Beedrill", beedrill_names},

    {"Pidgey", pidgey_names},
    {"Pidgeotto", pidgeotto_names},
    {"Pidgeot", pidgeot_names},

    {"Rattata", rattata_names},
    {"Raticate", raticate_names},

    {"Spearow", spearow_names},
    {"Fearow", fearow_names},

    {"Ekans", ekans_names},
    {"Arbok", arbok_names},

    {"Pikachu", pikachu_names},
    {"Raichu", raichu_names},

    {"Sandshrew", sandshrew_names},
    {"Sandslash", sandslash_names},

    {"Nidoran♀", nidoranf_names},
    {"Nidorina", nidorina_names},
    {"Nidoqueen", nidoqueen_names},

    {"Nidoran♂", nidoranm_names},
    {"Nidorino", nidorino_names},
    {"Nidoking", nidoking_names},

    {"Clefairy", clefairy_names},
    {"Clefable", clefable_names},

    {"Vulpix", vulpix_names},
    {"Ninetales", ninetales_names},

    {"Jigglypuff", jigglypuff_names},
    {"Wigglytuff", wigglytuff_names},

    {"Zubat", zubat_names},
    {"Golbat", golbat_names},

    {"Oddish", oddish_names},
    {"Gloom", gloom_names},
    {"Vileplume", vileplume_names},

    {"Paras", paras_names},
    {"Parasect", parasect_names},

    {"Venonat", venonat_names},
    {"Venomoth", venomoth_names},

    {"Diglett", diglett_names},
    {"Dugtrio", dugtrio_names},

    {"Meowth", meowth_names},
    {"Persian", persian_names},

    {"Psyduck", psyduck_names},
    {"Golduck", golduck_names},

    {"Mankey", mankey_names},
    {"Primeape", primeape_names},

    {"Growlithe", growlithe_names},
    {"Arcanine", arcanine_names},

    {"Poliwag", poliwag_names},
    {"Poliwhirl", poliwhirl_names},
    {"Poliwrath", poliwrath_names},

    {"Abra", abra_names},
    {"Kadabra", kadabra_names},
    {"Alakazam", alakazam_names},

    {"Machop", machop_names},
    {"Machoke", machoke_names},
    {"Machamp", machamp_names},

    {"Bellsprout", bellsprout_names},
    {"Weepinbell", weepinbell_names},
    {"Victreebel", victreebel_names},

    {"Tentacool", tentacool_names},
    {"Tentacruel", tentacruel_names},

    {"Geodude", geodude_names},
    {"Graveler", graveler_names},
    {"Golem", golem_names},

    {"Ponyta", ponyta_names},
    {"Rapidash", rapidash_names},

    {"Slowpoke", slowpoke_names},
    {"Slowbro", slowbro_names},

    {"Magnemite", magnemite_names},
    {"Magneton", magneton_names},

    {"Farfetch'd", farfetchd_names},

    {"Doduo", doduo_names},
    {"Dodrio", dodrio_names},

    {"Seel", seel_names},
    {"Dewgong", dewgong_names},

    {"Grimer", grimer_names},
    {"Muk", muk_names},

    {"Shellder", shellder_names},
    {"Cloyster", cloyster_names},

    {"Gastly", gastly_names},
    {"Haunter", haunter_names},
    {"Gengar", gengar_names},

    {"Onix", onix_names},

    {"Drowzee", drowzee_names},
    {"Hypno", hypno_names},

    {"Krabby", krabby_names},
    {"Kingler", kingler_names},

    {"Voltorb", voltorb_names},
    {"Electrode", electrode_names},

    {"Exeggcute", exeggcute_names},
    {"Exeggutor", exeggutor_names},

    {"Cubone", cubone_names},
    {"Marowak", marowak_names},

    {"Hitmonlee", hitmonlee_names},
    {"Hitmonchan", hitmonchan_names},

    {"Lickitung", lickitung_names},

    {"Koffing", koffing_names},
    {"Weezing", weezing_names},

    {"Rhyhorn", rhyhorn_names},
    {"Rhydon", rhydon_names},

    {"Chansey", chansey_names},

    {"Tangela", tangela_names},

    {"Kangaskhan", kangaskhan_names},

    {"Horsea", horsea_names},
    {"Seadra", seadra_names},

    {"Goldeen", goldeen_names},
    {"Seaking", seaking_names},

    {"Staryu", staryu_names},
    {"Starmie", starmie_names},

    {"Mr. Mime", mrmime_names},

    {"Scyther", scyther_names},

    {"Jynx", jynx_names},

    {"Electabuzz", electabuzz_names},

    {"Magmar", magmar_names},

    {"Pinsir", pinsir_names},

    {"Tauros", tauros_names},

    {"Magikarp", magikarp_names},
    {"Gyarados", gyarados_names},

    {"Lapras", lapras_names},

    {"Ditto", ditto_names},

    {"Eevee", eevee_names},
    {"Vaporeon", vaporeon_names},
    {"Jolteon", jolteon_names},
    {"Flareon", flareon_names},

    {"Porygon", porygon_names},

    {"Omanyte", omanyte_names},
    {"Omastar", omastar_names},

    {"Kabuto", kabuto_names},
    {"Kabutops", kabutops_names},

    {"Aerodactyl", aerodactyl_names},

    {"Snorlax", snorlax_names},

    {"Articuno", articuno_names},

    {"Zapdos", zapdos_names},

    {"Moltres", moltres_names},

    {"Dratini", dratini_names},
    {"Dragonair", dragonair_names},
    {"Dragonite", dragonite_names},

    {"Mewtwo", mewtwo_names},

    {"Mew", mew_names},


    // Gen 2
    {"Chikorita", chikorita_names},
    {"Bayleef", bayleef_names},
    {"Meganium", meganium_names},

    {"Cyndaquil", cyndaquil_names},
    {"Quilava", quilava_names},
    {"Typhlosion", typhlosion_names},

    {"Totodile", totodile_names},
    {"Croconaw", croconaw_names},
    {"Feraligatr", feraligatr_names},

    {"Sentret", sentret_names},
    {"Furret", furret_names},

    {"Hoothoot", hoothoot_names},
    {"Noctowl", noctowl_names},

    {"Ledyba", ledyba_names},
    {"Ledian", ledian_names},

    {"Spinarak", spinarak_names},
    {"Ariados", ariados_names},

    {"Crobat", crobat_names},

    {"Chinchou", chinchou_names},
    {"Lanturn", lanturn_names},

    {"Pichu", pichu_names},

    {"Cleffa", cleffa_names},

    {"Igglybuff", igglybuff_names},

    {"Togepi", togepi_names},
    {"Togetic", togetic_names},

    {"Natu", natu_names},
    {"Xatu", xatu_names},

    {"Mareep", mareep_names},
    {"Flaaffy", flaaffy_names},
    {"Ampharos", ampharos_names},

    {"Bellossom", bellossom_names},

    {"Marill", marill_names},
    {"Azumarill", azumarill_names},

    {"Sudowoodo", sudowoodo_names},

    {"Politoed", politoed_names},

    {"Hoppip", hoppip_names},
    {"Skiploom", skiploom_names},
    {"Jumpluff", jumpluff_names},

    {"Aipom", aipom_names},

    {"Sunkern", sunkern_names},
    {"Sunflora", sunflora_names},

    {"Yanma", yanma_names},

    {"Wooper", wooper_names},
    {"Quagsire", quagsire_names},

    {"Espeon", espeon_names},
    {"Umbreon", umbreon_names},

    {"Murkrow", murkrow_names},

    {"Slowking", slowking_names},

    {"Misdreavus", misdreavus_names},

    {"Unown", unown_names},

    {"Wobbuffet", wobbuffet_names},

    {"Girafarig", girafarig_names},

    {"Pineco", pineco_names},
    {"Forretress", forretress_names},

    {"Dunsparce", dunsparce_names},

    {"Gligar", gligar_names},

    {"Steelix", steelix_names},

    {"Snubbull", snubbull_names},
    {"Granbull", granbull_names},

    {"Qwilfish", qwilfish_names},

    {"Scizor", scizor_names},

    {"Shuckle", shuckle_names},

    {"Heracross", heracross_names},

    {"Sneasel", sneasel_names},

    {"Teddiursa", teddiursa_names},
    {"Ursaring", ursaring_names},

    {"Slugma", slugma_names},
    {"Magcargo", magcargo_names},

    {"Swinub", swinub_names},
    {"Piloswine", piloswine_names},

    {"Corsola", corsola_names},

    {"Remoraid", remoraid_names},
    {"Octillery", octillery_names},

    {"Delibird", delibird_names},

    {"Mantine", mantine_names},

    {"Skarmory", skarmory_names},

    {"Houndour", houndour_names},
    {"Houndoom", houndoom_names},

    {"Kingdra", kingdra_names},

    {"Phanpy", phanpy_names},
    {"Donphan", donphan_names},

    {"Porygon2", porygon2_names},

    {"Stantler", stantler_names},

    {"Smeargle", smeargle_names},

    {"Tyrogue", tyrogue_names},
    {"Hitmontop", hitmontop_names},

    {"Smoochum", smoochum_names},

    {"Elekid", elekid_names},

    {"Magby", magby_names},

    {"Miltank", miltank_names},

    {"Blissey", blissey_names},

    {"Raikou", raikou_names},

    {"Entei", entei_names},

    {"Suicune", suicune_names},

    {"Larvitar", larvitar_names},
    {"Pupitar", pupitar_names},
    {"Tyranitar", tyranitar_names},

    {"Lugia", lugia_names},

    {"Ho-oh", hooh_names},

    {"Celebi", celebi_names},


    // Gen 3
    {"Treecko", treecko_names},
    {"Grovyle", grovyle_names},
    {"Sceptile", sceptile_names},

    {"Torchic", torchic_names},
    {"Combusken", combusken_names},
    {"Blaziken", blaziken_names},

    {"Mudkip", mudkip_names},
    {"Marshtomp", marshtomp_names},
    {"Swampert", swampert_names},

    {"Poochyena", poochyena_names},
    {"Mightyena", mightyena_names},

    {"Zigzagoon", zigzagoon_names},
    {"Linoone", linoone_names},

    {"Wurmple", wurmple_names},
    {"Silcoon", silcoon_names},
    {"Beautifly", beautifly_names},
    {"Cascoon", cascoon_names},
    {"Dustox", dustox_names},

    {"Lotad", lotad_names},
    {"Lombre", lombre_names},
    {"Ludicolo", ludicolo_names},

    {"Seedot", seedot_names},
    {"Nuzleaf", nuzleaf_names},
    {"Shiftry", shiftry_names},

    {"Taillow", taillow_names},
    {"Swellow", swellow_names},

    {"Wingull", wingull_names},
    {"Pelipper", pelipper_names},

    {"Ralts", ralts_names},
    {"Kirlia", kirlia_names},
    {"Gardevoir", gardevoir_names},

    {"Surskit", surskit_names},
    {"Masquerain", masquerain_names},

    {"Shroomish", shroomish_names},
    {"Breloom", breloom_names},

    {"Slakoth", slakoth_names},
    {"Vigoroth", vigoroth_names},
    {"Slaking", slaking_names},

    {"Nincada", nincada_names},
    {"Ninjask", ninjask_names},
    {"Shedinja", shedinja_names},

    {"Whismur", whismur_names},
    {"Loudred", loudred_names},
    {"Exploud", exploud_names},

    {"Makuhita", makuhita_names},
    {"Hariyama", hariyama_names},

    {"Azurill", azurill_names},

    {"Nosepass", nosepass_names},

    {"Skitty", skitty_names},
    {"Delcatty", delcatty_names},

    {"Sableye", sableye_names},

    {"Mawile", mawile_names},

    {"Aron", aron_names},
    {"Lairon", lairon_names},
    {"Aggron", aggron_names},

    {"Meditite", meditite_names},
    {"Medicham", medicham_names},

    {"Electrike", electrike_names},
    {"Manectric", manectric_names},

    {"Plusle", plusle_names},

    {"Minun", minun_names},

    {"Volbeat", volbeat_names},

    {"Illumise", illumise_names},

    {"Roselia", roselia_names},

    {"Gulpin", gulpin_names},
    {"Swalot", swalot_names},

    {"Carvanha", carvanha_names},
    {"Sharpedo", sharpedo_names},

    {"Wailmer", wailmer_names},
    {"Wailord", wailord_names},

    {"Numel", numel_names},
    {"Camerupt", camerupt_names},

    {"Torkoal", torkoal_names},

    {"Spoink", spoink_names},
    {"Grumpig", grumpig_names},

    {"Spinda", spinda_names},

    {"Trapinch", trapinch_names},
    {"Vibrava", vibrava_names},
    {"Flygon", flygon_names},

    {"Cacnea", cacnea_names},
    {"Cacturne", cacturne_names},

    {"Swablu", swablu_names},
    {"Altaria", altaria_names},

    {"Zangoose", zangoose_names},

    {"Seviper", seviper_names},

    {"Lunatone", lunatone_names},

    {"Solrock", solrock_names},

    {"Barboach", barboach_names},
    {"Whiscash", whiscash_names},

    {"Corphish", corphish_names},
    {"Crawdaunt", crawdaunt_names},

    {"Baltoy", baltoy_names},
    {"Claydol", claydol_names},

    {"Lileep", lileep_names},
    {"Cradily", cradily_names},

    {"Anorith", anorith_names},
    {"Armaldo", armaldo_names},

    {"Feebas", feebas_names},
    {"Milotic", milotic_names},

    {"Castform", castform_names},

    {"Keckleon", keckleon_names},

    {"Shuppet", shuppet_names},
    {"Banette", banette_names},

    {"Duskull", duskull_names},
    {"Dusclops", dusclops_names},

    {"Tropius", tropius_names},

    {"Chimecho", chimecho_names},

    {"Absol", absol_names},

    {"Wynaut", wynaut_names},

    {"Snorunt", snorunt_names},
    {"Glalie", glalie_names},

    {"Spheal", spheal_names},
    {"Sealeo", sealeo_names},
    {"Walrein", walrein_names},

    {"Clamperl", clamperl_names},
    {"Huntail", huntail_names},
    {"Gorebyss", gorebyss_names},

    {"Relicanth", relicanth_names},

    {"Luvdisc", luvdisc_names},

    {"Bagon", bagon_names},
    {"Shelgon", shelgon_names},
    {"Salamence", salamence_names},

    {"Beldum", beldum_names},
    {"Metang", metang_names},
    {"Metagross", metagross_names},

    {"Regirock", regirock_names},

    {"Regice", regice_names},

    {"Registeel", registeel_names},

    {"Latias", latias_names},

    {"Latios", latios_names},

    {"Kyogre", kyogre_names},

    {"Groudon", groudon_names},

    {"Rayquaza", rayquaza_names},

    {"Jirachi", jirachi_names},

    {"Deoxys", deoxys_names},


    // Gen 4
    {"Turtwig", turtwig_names},
    {"Grotle", grotle_names},
    {"Torterra", torterra_names},

    {"Chimchar", chimchar_names},
    {"Monferno", monferno_names},
    {"Infernape", infernape_names},

    {"Piplup", piplup_names},
    {"Prinplup", prinplup_names},
    {"Empoleon", empoleon_names},

    {"Starly", starly_names},
    {"Staravia", staravia_names},
    {"Staraptor", staraptor_names},

    {"Bidoof", bidoof_names},
    {"Bibarel", bibarel_names},

    {"Kricketot", kricketot_names},
    {"Kricketune", kricketune_names},

    {"Shinx", shinx_names},
    {"Luxio", luxio_names},
    {"Luxray", luxray_names},

    {"Budew", budew_names},
    {"Roserade", roserade_names},

    {"Cranidos", cranidos_names},
    {"Rampardos", rampardos_names},

    {"Shieldon", shieldon_names},
    {"Bastiodon", bastiodon_names},

    {"Burmy", burmy_names},
    {"Wormadam", wormadam_names},
    {"Mothim", mothim_names},

    {"Combee", combee_names},
    {"Vespiquen", vespiquen_names},

    {"Pachirisu", pachirisu_names},

    {"Buizel", buizel_names},
    {"Floatzel", floatzel_names},

    {"Cherubi", cherubi_names},
    {"Cherrim", cherrim_names},

    {"Shellos", shellos_names},
    {"Gastrodon", gastrodon_names},

    {"Ambipom", ambipom_names},

    {"Drifloon", drifloon_names},
    {"Drifblim", drifblim_names},

    {"Buneary", buneary_names},
    {"Lopunny", lopunny_names},

    {"Mismagius", mismagius_names},

    {"Honchkrow", honchkrow_names},

    {"Glameow", glameow_names},
    {"Purugly", purugly_names},

    {"Chingling", chingling_names},

    {"Stunky", stunky_names},
    {"Skuntank", skuntank_names},

    {"Bronzor", bronzor_names},
    {"Bronzong", bronzong_names},

    {"Bonsly", bonsly_names},

    {"Mime Jr.", mimejr_names},

    {"Happiny", happiny_names},

    {"Chatot", chatot_names},

    {"Spiritomb", spiritomb_names},

    {"Gible", gible_names},
    {"Gabite", gabite_names},
    {"Garchomp", garchomp_names},

    {"Munchlax", munchlax_names},

    {"Riolu", riolu_names},
    {"Lucario", lucario_names},

    {"Hippopotas", hippopotas_names},
    {"Hippowdon", hippowdon_names},

    {"Skorupi", skorupi_names},
    {"Drapion", drapion_names},

    {"Croagunk", croagunk_names},
    {"Toxicroak", toxicroak_names},

    {"Carnivine", carnivine_names},

    {"Finneon", finneon_names},
    {"Lumineon", lumineon_names},

    {"Mantyke", mantyke_names},

    {"Snover", snover_names},
    {"Abomasnow", abomasnow_names},

    {"Weavile", weavile_names},

    {"Magnezone", magnezone_names},

    {"Lickilicky", lickilicky_names},

    {"Rhyperior", rhyperior_names},

    {"Tangrowth", tangrowth_names},

    {"Electivire", electivire_names},

    {"Magmortar", magmortar_names},

    {"Togekiss", togekiss_names},

    {"Yanmega", yanmega_names},

    {"Leafeon", leafeon_names},
    {"Glaceon", glaceon_names},

    {"Gliscor", gliscor_names},

    {"Mamoswine", mamoswine_names},

    {"Porygon-Z", porygonz_names},

    {"Gallade", gallade_names},

    {"Probopass", probopass_names},

    {"Dusknoir", dusknoir_names},

    {"Froslass", froslass_names},

    {"Rotom", rotom_names},

    {"Uxie", uxie_names},

    {"Mesprit", mesprit_names},

    {"Azelf", azelf_names},

    {"Dialga", dialga_names},

    {"Palkia", palkia_names},

    {"Heatran", heatran_names},

    {"Regigigas", regigigas_names},

    {"Giratina", giratina_names},

    {"Cresselia", cresselia_names},

    {"Phione", phione_names},
    {"Manaphy", manaphy_names},

    {"Darkrai", darkrai_names},

    {"Shaymin", shaymin_names},

    {"Arceus", arceus_names},


    // Gen 5
    {"Victini", victini_names},

    {"Snivy", snivy_names},
    {"Servine", servine_names},
    {"Serperior", serperior_names},

    {"Tepig", tepig_names},
    {"Pignite", pignite_names},
    {"Emboar", emboar_names},

    {"Oshawott", oshawott_names},
    {"Dewott", dewott_names},
    {"Samurott", samurott_names},

    {"Patrat", patrat_names},
    {"Watchog", watchog_names},

    {"Lillipup", lillipup_names},
    {"Herdier", herdier_names},
    {"Stoutland", stoutland_names},

    {"Purrloin", purrloin_names},
    {"Liepard", liepard_names},

    {"Pansage", pansage_names},
    {"Simisage", simisage_names},

    {"Pansear", pansear_names},
    {"Simisear", simisear_names},

    {"Panpour", panpour_names},
    {"Simipour", simipour_names},

    {"Munna", munna_names},
    {"Musharna", musharna_names},

    {"Pidove", pidove_names},
    {"Tranquill", tranquill_names},
    {"Unfezant", unfezant_names},

    {"Blitzle", blitzle_names},
    {"Zebstrika", zebstrika_names},

    {"Roggenrola", roggenrola_names},
    {"Boldore", boldore_names},
    {"Gigalith", gigalith_names},

    {"Woobat", woobat_names},
    {"Swoobat", swoobat_names},

    {"Drilbur", drilbur_names},
    {"Excadrill", excadrill_names},

    {"Audino", audino_names},

    {"Timburr", timburr_names},
    {"Gurdurr", gurdurr_names},
    {"Conkeldurr", conkeldurr_names},

    {"Tympole", tympole_names},
    {"Palpitoad", palpitoad_names},
    {"Seismitoad", seismitoad_names},

    {"Throh", throh_names},

    {"Sawk", sawk_names},

    {"Sewaddle", sewaddle_names},
    {"Swadloon", swadloon_names},
    {"Leavanny", leavanny_names},

    {"Venipede", venipede_names},
    {"Whirlipede", whirlipede_names},
    {"Scolipede", scolipede_names},

    {"Cottonee", cottonee_names},
    {"Whimsicott", whimsicott_names},

    {"Petilil", petilil_names},
    {"Lilligant", lilligant_names},

    {"Basculin", basculin_names},

    {"Sandile", sandile_names},
    {"Krokorok", krokorok_names},
    {"Krookodile", krookodile_names},

    {"Darumaka", darumaka_names},
    {"Darmanitan", darmanitan_names},

    {"Maractus", maractus_names},

    {"Dwebble", dwebble_names},
    {"Crustle", crustle_names},

    {"Scraggy", scraggy_names},
    {"Scrafty", scrafty_names},

    {"Sigilyph", sigilyph_names},

    {"Yamask", yamask_names},
    {"Cofagrigus", cofagrigus_names},

    {"Tirtouga", tirtouga_names},
    {"Carracosta", carracosta_names},

    {"Archen", archen_names},
    {"Archeops", archeops_names},

    {"Trubbish", trubbish_names},
    {"Garbodor", garbodor_names},

    {"Zorua", zorua_names},
    {"Zoroark", zoroark_names},

    {"Minccino", minccino_names},
    {"Cinccino", cinccino_names},

    {"Gothita", gothita_names},
    {"Gothorita", gothorita_names},
    {"Gothitelle", gothitelle_names},

    {"Solosis", solosis_names},
    {"Duosion", duosion_names},
    {"Reuniclus", reuniclus_names},

    {"Ducklett", ducklett_names},
    {"Swanna", swanna_names},

    {"Vanillite", vanillite_names},
    {"Vanillish", vanillish_names},
    {"Vanilluxe", vanilluxe_names},

    {"Deerling", deerling_names},
    {"Sawsbuck", sawsbuck_names},

    {"Emolga", emolga_names},

    {"Karrablast", karrablast_names},
    {"Escavalier", escavalier_names},

    {"Foongus", foongus_names},
    {"Amoongus", amoongus_names},

    {"Frillish", frillish_names},
    {"Jellicent", jellicent_names},

    {"Alomomola", alomomola_names},

    {"Joltik", joltik_names},
    {"Galvantula", galvantula_names},

    {"Ferroseed", ferroseed_names},
    {"Ferrothorn", ferrothorn_names},

    {"Klink", klink_names},
    {"Klang", klang_names},
    {"Klinklang", klinklang_names},

    {"Tynamo", tynamo_names},
    {"Eelektrik", eelektrik_names},
    {"Eelektross", eelektross_names},

    {"Elgyem", elgyem_names},
    {"Beheeyem", beheeyem_names},

    {"Litwick", litwick_names},
    {"Lampent", lampent_names},
    {"Chandelure", chandelure_names},

    {"Axew", axew_names},
    {"Fraxure", fraxure_names},
    {"Haxorus", haxorus_names},

    {"Cubchoo", cubchoo_names},
    {"Beartic", beartic_names},

    {"Cryogonal", cryogonal_names},

    {"Shelmet", shelmet_names},
    {"Accelgor", accelgor_names},

    {"Stunfisk", stunfisk_names},

    {"Mienfoo", mienfoo_names},
    {"Mienshao", mienshao_names},

    {"Druddigon", druddigon_names},

    {"Golett", golett_names},
    {"Golurk", golurk_names},

    {"Pawniard", pawniard_names},
    {"Bisharp", bisharp_names},

    {"Bouffalant", bouffalant_names},

    {"Rufflet", rufflet_names},
    {"Braviary", braviary_names},

    {"Vullaby", vullaby_names},
    {"Mandibuzz", mandibuzz_names},

    {"Heatmor", heatmor_names},

    {"Durant", durant_names},

    {"Deino", deino_names},
    {"Zweilous", zweilous_names},
    {"Hydreigon", hydreigon_names},

    {"Larvesta", larvesta_names},
    {"Volcarona", volcarona_names},

    {"Cobalion", cobalion_names},

    {"Terrakion", terrakion_names},

    {"Virizion", virizion_names},

    {"Tornadus", tornadus_names},

    {"Thundurus", thundurus_names},

    {"Reshiram", reshiram_names},

    {"Zekrom", zekrom_names},

    {"Landorus", landorus_names},

    {"Kyurem", kyurem_names},

    {"Keldeo", keldeo_names},

    {"Meloetta", meloetta_names},

    {"Genesect", genesect_names}
};

#endif //POKEMON_NICKNAME_GENERATOR_NAMES_H