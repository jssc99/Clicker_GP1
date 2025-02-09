#include "forge.h"

void draw_forge(Game *game)
{
    print_file(2, 9, "assets/forge.txt");

    // Forge dialog

    switch (game->forgeDialog)
    {
    case 0:
        im_print_text(1, 6, "Hello, I'm the lollypop maker.");
        im_print_text(1, 7, "I would do anything for some candies.");
        im_print_text(1, 8, "My lollypops are delicious!");
        break;

    case 1:
        im_print_text(1, 7, "Here you go.");
        break;

    case 2:
        im_print_text(1, 7, "My lollypops are delicious!");
        break;

    case 3:
        im_print_text(1, 7, "Somebody likes lollypops ahaha.");
        break;

    case 4:
    case 5:
        im_print_text(1, 6, "You seen to have a lot of candies on you.");
        im_print_text(1, 7, "I think you should also give a visit to a friend of mine.");
        im_print_text(1, 8, "He's a merchant next door, he'll have lots of stuff to sell to you!");
        if (game->featuresUnlocked == FORGE)
            game->featuresUnlocked++;
        break;

    default:
        im_print_text(1, 7, "Make sure you visit my good friend the merchant.");
        break;
    }

    // Buy lollypops

    if (im_button(1, 45, "One lollypop please. (60 candies)") && game->candy.amount >= 60)
    {
        game->candy.amount -= 60;
        game->lollypop.amount++;
        game->forgeDialog++;
    }

    // Secret lollypop

    if (game->check.foundForgeLolly == false)
    {
        if (im_button_quiet(25, 22, "--O"))
        {
            game->lollypop.amount++;
            game->check.foundForgeLolly = true;
        }
    }
    else
        im_print_text(1, 47, "You found the hidden lollypop!");
}