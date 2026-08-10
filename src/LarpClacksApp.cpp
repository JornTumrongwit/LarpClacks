#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "world/world.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace LarpClack;

class LarpClacksApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
private:
    World world;
};

void LarpClacksApp::setup()
{
    // Get the display geometry
    auto bounds = Display::getMainDisplay()->getBounds();

    // Resize the active window
    getWindow()->setSize(bounds.getSize());

    // Center the window on the screen
    getWindow()->setPos(bounds.getUL());

    ci::vec2 centerPoint = getWindowCenter();
    ci::vec2 dimensions = getWindowSize();

    //setting up the game world
    
    //placing the map tile
    world.map = MapTile(centerPoint, min(dimensions.x, dimensions.y)*0.8);
    world.map.SetColor(ci::Color(255.0 / 255, 255.0 / 255, 230.0 / 255));
    world.map.SetOutline(ci::Color(0, 0, 0.3), 30);

    //dummy player
    Player play(centerPoint, 30, &world);
    play.SetColor(ci::Color(255.0 / 255, 0 / 255, 0 / 255));
    play.SetOutline(ci::Color(0, 0, 0), 3);
    world.players.push_back(&play);

    // Enable smooth line blending
    ci::gl::enable(GL_LINE_SMOOTH);
    ci::gl::enable(GL_BLEND);

    // Hint to the GPU to prioritize line rendering quality
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void LarpClacksApp::mouseDown( MouseEvent event )
{
}

void LarpClacksApp::update()
{
}

void LarpClacksApp::draw()
{
	gl::clear( Color(255.0/510, 255.0/ 510, 230.0/ 510));
    gl::ScopedBlendAlpha alphaBlending;

    world.Draw();
}

CINDER_APP( LarpClacksApp, RendererGl )
