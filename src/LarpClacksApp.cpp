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
    world = World(this);

    //placing the map tile
    world.AddMap(centerPoint, min(dimensions.x, dimensions.y) * 0.8,
        ci::Color(255.0 / 255, 255.0 / 255, 230.0 / 255),
        ci::Color(0, 0, 0.3), 30);

    //dummy player
    world.AddPlayer(centerPoint, 30,
        ci::Color(255.0 / 255, 0 / 255, 0 / 255),
        ci::Color(0, 0, 0), 3);

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
    world.Update();
}

void LarpClacksApp::draw()
{
	gl::clear( Color(255.0/510, 255.0/ 510, 230.0/ 510));
    gl::ScopedBlendAlpha alphaBlending;

    world.Draw();
}

CINDER_APP( LarpClacksApp, RendererGl )
