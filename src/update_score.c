/*
** EPITECH PROJECT, 2020
** My_Defender
** File description:
** update_score.c
*/

#include <my_defender.h>

void score_loop(window_t *win, scene_t *scene, var_t *var)
{
    if (var->score != NULL) {
        sfText_setString(scene->write.text, var->score);
        sfText_setCharacterSize(scene->write.text, 32);
        free(var->score);
        var->score = NULL;
    }
    sfRenderWindow_drawText(win->window, scene->write.text, NULL);
}

void check_index(int *index, int i, char *old_score, int player_score)
{
    char **temp_score = my_str_to_word_array(old_score, " ");
    int len_array = my_strlen_array(temp_score);

    if (len_array <= 2)
        (*index) = i;
    else if (my_getnbr(temp_score[2]) < player_score)
        (*index) = i;
}

void write_new_score(int fd, int player_score, int wave, int index)
{
    char **new_score = my_str_to_word_array("1. Score: 1 Wave: 1", " ");
    char *score = to_str(player_score);
    char *wave_str = to_str(wave);

    new_score[0][0] = index + 1 + 48;
    free(new_score[2]);
    new_score[2] = score;
    free(new_score[4]);
    new_score[4] = wave_str;
    for (int i = 0; new_score[i]; i++) {
        write(fd, new_score[i], my_strlen(new_score[i]));
        write(fd, " ", 1);
    }
    free_array(new_score);
}

void write_to_file(var_t *var, int player_score, int index, char **old_score)
{
    char *filename = "assets/save_score.txt";
    int file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0666);
    int n = 0;

    for (int j = 0; j < 5; j++) {
        if (j == index) {
            write_new_score(file, player_score, var->wave.value, index);
        } else {
            old_score[n][0] = j + 1 + 48;
            write(file, old_score[n], my_strlen(old_score[n]));
            n++;
        }
        if (j != 4)
            write(file, "\n\n", 2);
    }
    close(file);
}

void update_score(var_t *var, map_t *map)
{
    int file = 0;
    char **old_score = read_file_array("assets/save_score.txt");
    stat_t stat;
    int score = 0;
    int index = -1;

    for (int i = 0; i < map->nb_obj; i++) {
        if (map->objects[i].type == TOWER) {
            stat = map->objects[i].stat;
            score += get_boost(stat.type, stat.power, stat.radius, stat.speed);
        }
    }
    score += var->money.value / 2;
    score += var->wave.value * 100;
    for (int i = 0; old_score[i] && index == -1 ; i++)
        check_index(&index, i, old_score[i], score);
    write_to_file(var, score, index, old_score);
    free_array(old_score);
    free(var->score);
    var->score = read_file("assets/save_score.txt");
}