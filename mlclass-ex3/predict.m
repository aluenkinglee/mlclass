function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%

action_1 = X;
% add one column vector (all element is one) to hidden layer 1 at the at one.
action_1 = [ones(m,1) action_1];

% action_1 is m * (n + 1)
% Theta1 is 25 * (n + 1) , so we need to transpose the theta1

z_2 =action_1 * Theta1';	

% hidden layer 1 (or layer 2) is m*25 now
action_2 = sigmoid(z_2);

% add column ones to hidden layer 1's parameters.
% now action_2 is m * 26.
action_2 = [ones(m,1) action_2]; 	

% results of m instances  m * 10.
predictions = sigmoid(action_2 * Theta2');

[max_v, p] = max(predictions, [], 2);





% =========================================================================


end
