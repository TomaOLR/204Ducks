/*
** EPITECH PROJECT, 2021
** 204Ducks
** File description:
** 204Ducks
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

float formule(float a, float t, int i)
{
    if (i == 0)
        return (-a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t));
    else
        return (a * exp(-t) + (4 - 3 * a) * exp(t * -2) + (2 * a - 4) * exp(t * -4));
}

int calc_time(float a, float max)
{
    float time = 1;

    for (; formule(a, time / 60.0, 0) + 1 < max; time += 0.01);
    return (time);
}

void average_deviation(float a)
{
    float avg = 0;
    float dev = 0;
    int sec = 0;

    for (float t = 0; t < 1000; t += 0.01)
        avg += formule(a, t, 1) * t * 0.01;
    sec = ceil((avg - (int)avg) * 60);
    printf("Average return time: %dm %ds\n", (int)avg, sec);
    for (float t = 0; t < 1000; t += 0.01)
        dev += formule(a, t, 1) * pow(t - avg, 2) * 0.01;
    printf("Standard deviation: %.3f\n", sqrt(dev));
}

void print(float a)
{
    int time1 = calc_time(a, 0.50);
    int time2 = calc_time(a, 0.99);
    float percent_1 = (formule(a, 1, 0) + 1) * 100;
    float percent_2 = (formule(a, 2, 0) + 1) * 100;

    average_deviation(a);
    printf("Time after which 50%% of the ducks are back: %dm %d%ds\n", time1 / 60, time1 % 60 / 10, time1 % 10);
    printf("Time after which 99%% of the ducks are back: %dm %d%ds\n", time2 / 60, time2 % 60 / 10, time2 % 10);
    printf("Percentage of ducks back after 1 minute: %.1f%%\n", percent_1);
    printf("Percentage of ducks back after 2 minutes: %.1f%%\n", percent_2);
}
