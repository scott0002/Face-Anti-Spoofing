%??directory?file_path?????????x?label y
function [x,y]=readimg(file_path)
x=[];
y=[];
img_path_list = dir(strcat(file_path,'*.png'));
img_num = length(img_path_list);
if img_num > 0 
        for j = 1:img_num 
            image_name = img_path_list(j).name;
            image =  imread(strcat(file_path,image_name));
            if img_num==1000
                fprintf('%d %d %s\n',i,j,strcat(file_path,image_name));
            end
            %image???? 
            image = imresize(image,[299 299]);
            x=[x,image];
            if strncmp(image_name, "real_", 5)==1
                label=1;
            else
                label=0;
            end
            y=[y,label];
        end
end