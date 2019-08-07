#include <equal/core/scene.hpp>
#include <equal/core/application.hpp>
#include <equal/core/logger.hpp>
#include <equal/helper/error.hpp>
#include <equal/helper/system.hpp>
#include <equal/helper/error.hpp>

namespace eq {

Scene::Scene() {
  m_event = new EventSystem();
  m_component = new ComponentSystem();
  m_script = new ScriptSystem();
}

Scene::~Scene() {
  GetWindow()->capture_events(false);
  end();
  delete m_event;
  delete m_script;
  delete m_component;
  delete m_canvas;
  m_objects.clear();
}

World *Scene::world() const { return m_world; }

void Scene::world(World *world) { m_world = world; }

EventSystem *Scene::event_system() const { return m_event; }

ComponentSystem *Scene::component_system() const { return m_component; }

ScriptSystem *Scene::script_system() const { return m_script; }

void Scene::canvas(ui::Canvas *canvas) {
  if (canvas) {
    if (m_canvas) {
      delete m_canvas;
    }
    m_canvas = canvas;
  } else {
    EQ_THROW("Can't define a invalid canvas");
  }
}

ui::Canvas *Scene::canvas() const { return m_canvas; }

std::vector<GameObject *> Scene::objects() const { return m_objects; }

void Scene::add(GameObject *object) {
  if (object) {
    m_objects.push_back(object);
  } else {
    EQ_CORE_WARN("Invalid object to add on scene");
  }
}

void Scene::update(const Timestep &timestep) {
  // Start scene
  if (!m_initialized) {
    m_canvas = new ui::Canvas(Position{0, 0}, GetWindow()->size());
    start();
    m_component->start();
    m_script->start();
    m_event->start();
    m_initialized = true;
    GetWindow()->capture_events(true);
  }

  m_component->update(timestep);
  m_script->update(timestep);

  update(m_world, timestep);
}

void Scene::fixed_update(const Timestep &timestep) {
  m_component->fixed_update(timestep);
  m_script->fixed_update(timestep);

  fixed_update(m_world, timestep);
}

} // namespace eq
