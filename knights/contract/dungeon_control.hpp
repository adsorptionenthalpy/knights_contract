#pragma once

class dungeon_control : public control_base {
private:
    account_name self;
    item_control &item_controller;
    admin_control &admin_controller;
    player_control &player_controller;

    rule_controller<rdungeon, rdungeon_table> dungeon_rule_controller;
    rule_controller<rmobs, rmobs_table> mobs_rule_controller;
    rule_controller<rmobskills, rmobskills_table> mobskills_rule_controller;

public:
    // constructor
    //-------------------------------------------------------------------------
    dungeon_control(account_name _self,
                    item_control &_item_controller,
                    player_control &_player_controller,
                    admin_control &_admin_controller)
        : self(_self)
        , dungeon_rule_controller(_self, N(dungeon))
        , mobs_rule_controller(_self, N(mobs))
        , mobskills_rule_controller(_self, N(mobskills))
        , item_controller(_item_controller)
        , player_controller(_player_controller)
        , admin_controller(_admin_controller) {
    }


    rule_controller<rdungeon, rdungeon_table>& get_dungeon_rule() {
        return dungeon_rule_controller;
    }

    rule_controller<rmobs, rmobs_table>& get_mobs_rule() {
        return mobs_rule_controller;
    }

    rule_controller<rmobskills, rmobskills_table>& get_mobskills_rule() {
        return mobskills_rule_controller;
    }    
};