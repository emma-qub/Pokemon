#include "Mapping.hxx"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cassert>

Mapping::Mapping(const std::string& p_fileName,
  unsigned int p_locationX, unsigned int p_locationY,
  unsigned int p_lineCount, unsigned int p_columnCount):

  m_location(p_locationX, p_locationY),
  m_lineCount(p_lineCount),
  m_columnCount(p_columnCount) {

  computeGlobalLocation();

  std::ifstream infile;
  infile.open(p_fileName, std::ios::in);

  std::string strLine;

  if (infile) {
    while (getline(infile, strLine)) {
      std::string delimiter = ",";
      size_t pos = 0;
      std::string token;
      while ((pos = strLine.find(delimiter)) != std::string::npos) {
        token = strLine.substr(0, pos);
        m_mapVector.push_back(static_cast<BackgroundType>(atoi(token.c_str())));
        strLine.erase(0, pos + delimiter.length());
      }
      std::cerr << std::endl;
    }
  } else {
    std::runtime_error("Mapping::Mapping - Failed to open " + p_fileName);
  }
}

void Mapping::computeGlobalLocation(void) {
  m_globalLocation = m_location.second*m_columnCount + m_location.first;
}

Mapping::BackgroundType Mapping::getBackgroundTypeUp(void) const {
  if (m_location.second == 0)
    return BackgroundType::none;
  else
    return m_mapVector.at(m_globalLocation-m_columnCount);
}

Mapping::BackgroundType Mapping::getBackgroundTypeDown(void) const {
  if (m_location.second == m_lineCount-1)
    return BackgroundType::none;
  else
    return m_mapVector.at(m_globalLocation+m_columnCount);
}

Mapping::BackgroundType Mapping::getBackgroundTypeLeft(void) const {
  if (m_location.first == 0)
    return BackgroundType::none;
  else
    return m_mapVector.at(m_globalLocation-1);
}

Mapping::BackgroundType Mapping::getBackgroundTypeRight(void) const {
  if (m_location.first == m_columnCount-1)
    return BackgroundType::none;
  else
    return m_mapVector.at(m_globalLocation+1);
}

void Mapping::goToUp(void) {
  assert(m_location.second > 0);

  m_location.second--;
  computeGlobalLocation();
}
void Mapping::goToDown(void) {
  assert(m_location.second < m_lineCount-1);

  m_location.second++;
  computeGlobalLocation();
}

void Mapping::goToLeft(void) {
  assert(m_location.first > 0);

  m_location.first--;
  computeGlobalLocation();
}

void Mapping::goToRight(void) {
  assert(m_location.first < m_columnCount-1);

  m_location.first++;
  computeGlobalLocation();
}

