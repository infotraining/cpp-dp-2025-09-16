#include "circle_reader_writer.hpp"
#include "../shape_factories.hpp"
#include "../circle.hpp"

using namespace std;
using namespace Drawing;
using namespace Drawing::IO;

// TODO - register CircleReaderWriter creator in a factory
namespace
{
    bool is_registered = SingletonShapeRWFactory::instance().register_creator(make_type_index<Circle>(), []() { return make_unique<CircleReaderWriter>(); });
}
