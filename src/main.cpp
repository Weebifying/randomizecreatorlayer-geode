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

		auto menu = this->getChildByID("creator-buttons-menu");

		// thanks catto	
		for(auto node : CCArrayExt<CCNode*>(this->getChildren())) {
<<<<<<< HEAD
			if (node->getChildrenCount() == 100) menu = node;
		}

		// making a shuffled index array
		// ik this isnt optimized but stfu it works sob
=======
			log::info("{} {}", node->getID(), node->getChildrenCount());
			if (node->getChildrenCount() == 100) menu = node;
		}

	        auto menu_copy = menu;

		log::info("found cologne thing {}", menu->getChildrenCount());

>>>>>>> 6807ba09a541b1aef730689d97188260474caeeb
		int count = menu->getChildrenCount();
		int* a = new int[count];
		for (int i = 0; i < count; i++) {
			a[i] = i;
		}
		std::shuffle(a, a + count, std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
		
<<<<<<< HEAD
		// also very NOT optimized but
		// any way i can get an element out of the CCArray returns a CCObject instead so i cant do shit
		// so please do tell me if theres a better way
		CCPoint* pa = new CCPoint[count+1];
		int x = 0;
		for(auto node : CCArrayExt<CCNode*>(menu->getChildren())) {
			pa[x] = node->getPosition();
			x++;
		}
		x = 0;
		for(auto node : CCArrayExt<CCNode*>(menu->getChildren())) {
			node->setPosition(pa[a[x]]);
			x++;
=======
		for(auto node : CCArrayExt<CCNode*>(menu->getChildren())) {
			//node->setPosition();
			//menu_copy->getChildren()->objectAtIndex(i)->getPosition()
		}

		for (int i = 0, i < count, i++) {
			menu->getChildren()->objectAtIndex(i)->setPosition(
				menu_copy->getChildren()->objectAtIndex(a[i])->getPositionX(),
				menu_copy->getChildren()->objectAtIndex(a[i])->getPositionY()
			);
			
>>>>>>> 6807ba09a541b1aef730689d97188260474caeeb
		}

		return true;
	}
<<<<<<< HEAD
};
=======
};

		
>>>>>>> 6807ba09a541b1aef730689d97188260474caeeb
