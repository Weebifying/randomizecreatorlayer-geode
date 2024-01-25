#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

#include <algorithm>
#include <random>
#include <chrono>


using namespace geode::prelude;

class $modify(AltCreatorLayer, CreatorLayer) {
	static void onModify(auto& self) {
		self.setHookPriority("CreatorLayer::init", -100);
	}

	bool init() {
		if (!CreatorLayer::init()) return false;

		// thanks catto	

		auto menu = this->getChildByID("creator-buttons-menu");

		for(auto node : CCArrayExt<CCNode*>(this->getChildren())) {
			log::info("{} {}", node->getID(), node->getChildrenCount());
			if (node->getChildrenCount() == 100) menu = node;
		}

	        auto menu_copy = menu;

		log::info("found cologne thing {}", menu->getChildrenCount());

		int count = menu->getChildrenCount();
		int* a = new int[count];
		for (int i = 0; i < count; i++) {
			a[i] = i;
		}
		std::shuffle(a, a + count, std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

		for (int i = 0; i < count; i++) log::info("{}", a[i]);
		
		for(auto node : CCArrayExt<CCNode*>(menu->getChildren())) {
			//node->setPosition();
			//menu_copy->getChildren()->objectAtIndex(i)->getPosition()
		}

		for (int i = 0, i < count, i++) {
			menu->getChildren()->objectAtIndex(i)->setPosition(
				menu_copy->getChildren()->objectAtIndex(a[i])->getPositionX(),
				menu_copy->getChildren()->objectAtIndex(a[i])->getPositionY()
			);
			
		}

		return true;
	}
};

		
