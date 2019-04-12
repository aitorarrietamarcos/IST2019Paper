function [dc] = getDc(activationArray, data_objects, system)
    %open(model);
    init = 0;
    if(sum(activationArray) == 0)
       dc = 0; 
    else
        for i=1:size(activationArray,2)
            if(activationArray(i) == 1)
                if init == 0
                    covdata = data_objects{i};
                    init = 1;
                else
                    covdata = data_objects{i} + covdata;
                end
            end
        end
        
        blk_handle = get_param(system,'Handle');

        decisiondata = decisioninfo(covdata,blk_handle);
        dc = decisiondata(1)/decisiondata(2);
    end

end