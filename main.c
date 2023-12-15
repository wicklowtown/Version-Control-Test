// Using guidance from Lecture 1, I added a basic Raylib structure.
// (From https://chirag4862.hashnode.dev/getting-started-with-raylib-for-game-development-in-c#)

#include "raylib.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(1280, 720, "Fenian Ram 3000");

    Font customFont = LoadFont("grasping.ttf");
    Font customFont2 = LoadFont("COMICATE.TTF");
    Font customFont3 = LoadFont("Outwrite.ttf");

    DrawText("Deep, Dark, Depths...");
    DrawTextureEx(customFont2);
    Vector2 textPosition = {10,screenHeight/1 -45};
    int textSize = 45;
    Color textColor = LIME;

    SetTargetFPS(60);

    // Using guidance from Lecture 3, I began to load textures, add vectors and more.
    // The first image I added was a test for the playable sprite - the submarine.
    Texture2D submarine1 = LoadTexture("submarine.png");
Vector2 scale = {0.5f/0.5f};

     float rotation = 0.0f;
     Color tint = WHITE;

    Vector2 position = {(screenWidth - (submarine1.width* scale.x))/2, (screenHeight- (submarine1.height * scale.y))/2};
const float moveSpeed = 5.0f;

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

// Using further guidance from Lecture 3, I added movement inputs to the sprite.
       if(IsKeyDown(KEY_RIGHT)) position.x += moveSpeed;
       if(IsKeyDown(KEY_LEFT)) position.x -= moveSpeed;
       if(IsKeyDown(KEY_UP)) position.y -= moveSpeed;
       if(IsKeyDown(KEY_DOWN)) position.y += moveSpeed;

       if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) rotation -= 10.0f;
               if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) rotation += 10.0f;

       BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText(text, textPosition.x, textPosition.y, textSize, textColor);
        DrawText("Level 1:", 10, screenHeight-75, 35,PINK);

        DrawTextEx(customFont, "Use the arrows to move!", (Vector2){ screenWidth/100, 0}, customFont.baseSize, 2, BLACK);

        DrawTextureEx(submarine1, position, rotation, 0.5f, tint);



        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(submarine1);
    UnloadFont(customFont);
    CloseWindow();
    return 0;
}
