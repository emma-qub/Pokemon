#ifndef MAPPING_HXX
#define MAPPING_HXX

#include <string>
#include <vector>

class Mapping {

public:
  enum BackgroundType {
    walkable = 0,
    enterable = 1,
    cuttable = 2,
    readable = 3,
    swimable = 4,
    downjumpable = 5,
    rightjumpable = 6,
    leftjumpable = 7,
    forbidden = 8,
    none = 9
  };

public:
  explicit Mapping(const std::string& p_fileName,
    unsigned int p_locationX, unsigned int p_locationY,
    unsigned int p_lineCount, unsigned int p_columnCount);

  BackgroundType getBackgroundTypeUp(void) const;
  BackgroundType getBackgroundTypeDown(void) const;
  BackgroundType getBackgroundTypeLeft(void) const;
  BackgroundType getBackgroundTypeRight(void) const;

  void goToUp(void);
  void goToDown(void);
  void goToLeft(void);
  void goToRight(void);

private:
  void computeGlobalLocation(void);

public:
  std::vector<BackgroundType> m_mapVector;
  std::pair<int, int> m_location;
  int m_lineCount;
  int m_columnCount;
  int m_globalLocation;
};

#endif // MAPPING_HXX
