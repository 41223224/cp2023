#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width / 4);
    int center_y = (int)(height / 4);
    int sun_radius = (int)(width / 8);
    int white_circle_dia = sun_radius;
    int blue_circle_dia = white_circle_dia + white_circle_dia * 2 / 15;

    red = gdImageColorAllocate(img, 255, 0, 0);
    white = gdImageColorAllocate(img, 255, 255, 255);
    blue = gdImageColorAllocate(img, 0, 0, 149);

    gdImageFilledRectangle(img, 0, 0, width, height, red);
    gdImageFilledRectangle(img, 0, 0, (int)(width / 2.0), (int)(height / 2.0), blue);

    draw_white_sun(img, center_x, center_y, sun_radius, white);

    gdImageFilledEllipse(img, center_x, center_y, blue_circle_dia, blue_circle_dia, blue);
    gdImageFilledEllipse(img, center_x, center_y, white_circle_dia, white_circle_dia, white);
}

void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int color) {
    float deg = M_PI / 180;

    int second_ax = center_x;
    int second_ay = center_y - sun_radius;
    int second_bx = center_x - sun_radius * tan(15 * deg);
    int second_by = center_y;
    int second_ex = center_x;
    int second_ey = center_y + sun_radius;
    int second_dx = center_x + sun_radius * tan(15 * deg);
    int second_dy = center_y;

    gdImageLine(img, second_ax, second_ay, second_bx, second_by, color);
    gdImageLine(img, second_bx, second_by, second_ex, second_ey, color);
    gdImageLine(img, second_ex, second_ey, second_dx, second_dy, color);
    gdImageLine(img, second_dx, second_dy, second_ax, second_ay, color);
}