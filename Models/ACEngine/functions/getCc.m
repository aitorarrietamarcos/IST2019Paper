function [cc] = getCc(activationArray, data_objects, system)
    %open(model);
    init = 0;
    if(sum(activationArray) == 0)
       cc = 0; 
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

        conditiondata = conditioninfo(covdata,blk_handle);
        cc = conditiondata(1)/conditiondata(2);
    end

end