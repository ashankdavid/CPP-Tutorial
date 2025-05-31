#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

enum Rarity { Common, Uncommon, Rare, Epic, Legendary };

struct Artifact {
    std::string name;
    std::string era;
    int powerLevel;
    Rarity rarity;
};

class ArtifactCollection {
private:
    std::unordered_map<std::string, Artifact> artifactMap;
    std::map<int, Artifact, std::greater<int>> powerMap;

public:
    void insertArtifact(const Artifact& artifact) {
        artifactMap[artifact.name] = artifact;
        powerMap[artifact.powerLevel] = artifact;
    }

    void removeArtifact(const std::string& name) {
        if (artifactMap.count(name)) {
            int powerLevel = artifactMap[name].powerLevel;
            artifactMap.erase(name);
            powerMap.erase(powerLevel);
        }
    }

    Artifact mostPowerfulInEra(const std::string& era) {
        for (const auto& entry : artifactMap) {
            if (entry.second.era == era) {
                return entry.second;
            }
        }
        throw std::runtime_error("No artifact found from the given era.");
    }

    Artifact rarestArtifact() {
        return powerMap.begin()->second;
    }

    int totalPowerInEra(const std::string& era) {
        int totalPower = 0;
        for (const auto& entry : artifactMap) {
            if (entry.second.era == era) {
                totalPower += entry.second.powerLevel;
            }
        }
        return totalPower;
    }
};

int main() {
    ArtifactCollection collection;

    // Example usage
    Artifact artifact1{"Scepter of Eldoria", "Ancient", 950, Legendary};
    Artifact artifact2{"Crystal Amulet", "Medieval", 620, Rare};

    collection.insertArtifact(artifact1);
    collection.insertArtifact(artifact2);

    Artifact mostPowerful = collection.mostPowerfulInEra("Medieval");
    std::cout << "Most Powerful in Medieval Era: " << mostPowerful.name << std::endl;

    Artifact rarest = collection.rarestArtifact();
    std::cout << "Rarest Artifact: " << rarest.name << std::endl;

    int totalPower = collection.totalPowerInEra("Ancient");
    std::cout << "Total Power in Ancient Era: " << totalPower << std::endl;

    return 0;
}
