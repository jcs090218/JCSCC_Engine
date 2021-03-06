-- ========================================================================
-- $File: Player.lua $
-- $Date: 2015-09-10 11:34:10 $
-- $Revision: $
-- $Creator: Jen-Chieh Shen $
-- $Notice: See LICENSE.txt for modification and distribution information $
--                   Copyright (c) 2015 by Shen, Jen-Chieh $
-- ========================================================================


 require "Keys"

 local dir = 0.0
 local scaledir = 1.0
 local moving = false

 function on_update(own, d)
    if Input.getKeyDown(Keys.K_LEFT) then
        dir = -1.0
        scaledir = -1.0
        moving = true
        own:setcurrentanimation("run")
    elseif Input.getKeyDown(Keys.K_RIGHT) then
        dir = 1.0
        scaledir = 1.0
        moving = true
        own:setcurrentanimation("stand")
    end

    if moving then
        own:getteransform():movd(4.0 * dir, 0.0, 0.0)
    end
    own:gettransform():setscale(Vector3(scaledir, 1.0, 1.0))
 end

