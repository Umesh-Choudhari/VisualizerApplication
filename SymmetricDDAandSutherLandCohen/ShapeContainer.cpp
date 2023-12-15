#include "stdafx.h"
#include "ShapeContainer.h"

using namespace symmetricDDAandSutherlandCohen;

ShapeContainer::ShapeContainer()
{

}

ShapeContainer::~ShapeContainer()
{

}

std::vector<Line>& ShapeContainer::inLines()
{
	return inputLines;
}
std::vector<Line>& ShapeContainer::clipedLines()
{
	return mClipedLines;
}

