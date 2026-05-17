var rules = [
    [["hello", "hi", "hey"],        "Hello! Welcome to ShopEasy support. How can I help you?"],
    [["order", "track", "status"],  "To track your order, go to My Orders and enter your Order ID."],
    [["return", "refund"],          "We have a 30-day return policy. Refunds take 5-7 business days."],
    [["cancel"],                    "You can cancel an order within 24 hours from My Orders section."],
    [["payment", "pay", "card"],    "We accept credit/debit cards, UPI, net banking, and cash on delivery."],
    [["discount", "coupon"],        "Use code SAVE10 for 10% off on your first order!"],
    [["delivery", "shipping"],      "Standard delivery takes 3-5 business days."],
    [["hour", "open", "timing"],    "We are open Mon-Sat 9AM to 8PM, Sunday 10AM to 6PM."],
    [["contact", "phone", "email"], "Call us at 1800-123-4567 or email support@shopeasy.com."],
    [["thank", "bye"],              "Thank you for contacting ShopEasy! Have a great day."]
];

var defaultReply = "I didn't understand. You can ask about orders, returns, payments, or delivery.";

function getResponse(message) {
    var msg = message.toLowerCase();
    for (var i = 0; i < rules.length; i++) {
        var keywords = rules[i][0];
        var reply    = rules[i][1];
        for (var j = 0; j < keywords.length; j++) {
            if (msg.includes(keywords[j])) {
                return reply;
            }
        }
    }
    return defaultReply;
}
